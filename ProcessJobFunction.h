#ifndef PROCESS_JOB_FUNCTION
#define PROCESS_JOB_FUNCTION
#include <iostream>
#include <cstdint>
#include "CFSAlgorithm.h"
#include "Structure.h"

// This file contains implementation of functions that are mapping with every node in process task

class ProcessJobFunction : public CFSAlgorithm
{
private:
    gtask taskTable[NUMBER_OF_TASKS];

public:
    ProcessJobFunction();
    ~ProcessJobFunction();

    void taskinit();
    void runtask();
};
#endif