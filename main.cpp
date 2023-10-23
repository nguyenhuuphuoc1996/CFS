#include <iostream>
#include "CFSAlgorithm.h"

int main()
{
    uint64_t taskTable[2]{8, 10};
    CFSAlgorithm cfs1;
    cfs1.CFSCreateProcessTree(taskTable, 2);
    cfs1.CFSTaskProcessing();

    std::cout << "-------------" << std::endl;
    // Main execution here
    // TBD
}
