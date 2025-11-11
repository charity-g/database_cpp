#include <iostream>
#define TOTAL_CYLINDERS 5000
#define TOTAL_PLATTERS 10
#define IS_DOUBLE_SIDED true




int main(int argc, char **argv)
{
    std::cout << argc << " arguments provided.\n";
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "Argument " << i << ": " << argv[i] << "\n";
    }
    return 0;
}