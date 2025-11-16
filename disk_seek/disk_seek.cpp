#include <iostream>
#include <string>
#define TOTAL_CYLINDERS 5000
#define STARTING_CYLINDER 0 //[[maybe unused]]
#define TOTAL_PLATTERS 10 //[[maybe unused]]
#define IS_DOUBLE_SIDED true //[[maybe unused]]


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

float CalculateSeekTime(int from_cylinder, int to_cylinder) {
    // Placeholder for seek time calculation logic
}

float CalculateRotationalLatency() {
    // Placeholder for rotational latency calculation logic
}

float CalculateTransferTime() {
    // Placeholder for transfer time calculation logic
}

void SimulateDiskSeek(int * requests, int total_requests) {
    int curr_cylinder = STARTING_CYLINDER;
    
    for (int i = 0; i < total_requests; ++i) {
        // we are at starting cylinder
        std::cout << "Seeking to cylinder: " << requests[i] << "\n";
        curr_cylinder = requests[i];
    }
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