#ifndef CFS_ALGORITHM
#define CFS_ALGORITHM
#include <stdio.h>
#include <cstdint>
#include "RedBlackTreeDS.h"

#define STUB_TIME_QUANTUM 4 // 1 time quantum = 4ms

struct cfs_Task
{
    Node *cfs_TaskRepresentNode;
    uint64_t cfs_task_timevirtual;
};

class CFSAlgorithm : public Red_Black_Tree
{
private:
    uint64_t cfs_number_of_task;
    uint64_t cfs_time_quantum_per_task;

public:
    CFSAlgorithm();
    ~CFSAlgorithm();

    void CFSCreateProcessTree(int p_array[], int p_length);
    void CFSTaskProcessing();
};

#endif