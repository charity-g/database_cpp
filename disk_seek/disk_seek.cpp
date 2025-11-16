#include <iostream>
#include <string>
#define TOTAL_CYLINDERS 5000
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

void SimulateDiskSeek(int * requests, int total_requests) {
    // Simulation logic would go here
    for (int i = 0; i < total_requests; ++i) {
        std::cout << "Seeking to cylinder: " << requests[i] << "\n";
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