#include <iostream>
#define TOTAL_CYLINDERS 5000
#define TOTAL_PLATTERS 10 //[[maybe unused]]
#define IS_DOUBLE_SIDED true //[[maybe unused]]


int * parse_disk_seek_requests(char **argv)
{
    // Placeholder for actual validation logic
    return nullptr;

}

int main(int argc, char **argv)
{
    int * requests { parse_disk_seek_requests(argv) };
    if (!requests)
    {
        std::cerr << "Invalid disk seek inputs provided. Must be list of number within " << TOTAL_CYLINDERS << " \n";
        return 1;
    }
    std::cout << argc << " arguments provided.\n";
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "Argument " << i << ": " << argv[i] << "\n";
    }
    return 0;
}