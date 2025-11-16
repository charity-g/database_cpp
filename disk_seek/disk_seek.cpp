#include <iostream>
#include <string>
#include <cmath>
#define TOTAL_CYLINDERS 5000
#define STARTING_CYLINDER 0 //[[maybe unused]]
#define TOTAL_PLATTERS 10 //[[maybe unused]]
#define IS_DOUBLE_SIDED true //[[maybe unused]]
#define RPM 7200 //[[maybe unused]]
#define BYTES_PER_TRACK 49152 //[[maybe unused]]

int * ParseDiskSeekRequests(int argc, char **argv) {
    int * requests = new int[argc - 1];
    for (int i = 1; i < argc; ++i) {
        int request {};
        try {
            request = std::stoi(argv[i]);
        } catch (const std::exception& e) {
            delete[] requests;
            return nullptr;
        }

        if (request < 0 || request >= TOTAL_CYLINDERS) {
            delete[] requests;
            return nullptr;
        } else {
            requests[i - 1] = request;
        }
    }
    return requests;

}

// Returns seek time in ms
float CalculateSeekTime(int from_cylinder, int to_cylinder) {
    // Placeholder for seek time calculation logic
    float setup_time = 3.0f; // ms
    float time_per_cylinder = 0.1f; // ms per cylinder
    int cylinder_distance = std::abs(to_cylinder - from_cylinder);
    return setup_time + (time_per_cylinder * cylinder_distance);
}


// Returns average rotational latency in ms
float CalculateRotationalLatency() {
    return RPM / 60000.0f * 0.5f;
}

// Returns transfer time for one page in ms
float CalculateTransferTime() {
    return (RPM / 60000.0f) *  4096.0f / static_cast<float>(BYTES_PER_TRACK);
}

void SimulateDiskSeek(int * requests, int total_requests) {
    int curr_cylinder = STARTING_CYLINDER;
    float grand_total_time = 0.0f;
    for (int i = 0; i < total_requests; ++i) {
        float seek_time = CalculateSeekTime(curr_cylinder, requests[i]);
        float rotational_latency = CalculateRotationalLatency();
        float transfer_time = CalculateTransferTime();
        float total_time = seek_time + rotational_latency + transfer_time;
        std::cout << "Retrieving page on cylinder: " << requests[i] << "\n";
        std::cout << "Total time for operation: " << total_time << " ms\n";
        grand_total_time += total_time;
        curr_cylinder = requests[i];
    }
    std::cout << "Grand total time for all operations: " << grand_total_time << " ms\n";
}

int main(int argc, char **argv)
{
    int * requests { ParseDiskSeekRequests(argc, argv) };
    if (!requests)
    {
        std::cerr << "Invalid disk seek inputs provided. Must be list of number within " << TOTAL_CYLINDERS << " \n";
        return 1;
    }
    SimulateDiskSeek(requests, argc - 1);
    delete[] requests;
    return 0;
}