#include <iostream>
#include "CFSAlgorithm.h"

int main()
{
    uint64_t taskTable[6]{1, 2, 4, 5, 7, 5};
    CFSAlgorithm cfs1;
    cfs1.CFSCreateProcessTree(taskTable, sizeof(taskTable) / sizeof(uint64_t));
    cfs1.CFSTaskProcessing();

    std::cout << "-------------" << std::endl;
    // Main execution here
}
