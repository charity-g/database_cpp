#include <iostream>
#include <string>
#define TOTAL_CYLINDERS 5000
#define TOTAL_PLATTERS 10 //[[maybe unused]]
#define IS_DOUBLE_SIDED true //[[maybe unused]]


int * parse_disk_seek_requests(int argc, char **argv) {
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

int main(int argc, char **argv)
{
    int * requests { parse_disk_seek_requests(argc, argv) };
    if (!requests)
    {
        std::cerr << "Invalid disk seek inputs provided. Must be list of number within " << TOTAL_CYLINDERS << " \n";
        return 1;
    }
    std::cout << argc - 1 << " disk seek requests provided.\n";
    for (int i = 1; i < argc; ++i)
    {
        std::cout << "Argument " << i << ": " << requests[i] << "\n";
    }
    return 0;
}