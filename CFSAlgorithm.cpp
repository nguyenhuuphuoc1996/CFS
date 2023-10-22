#include "CFSAlgorithm.h"

CFSAlgorithm::CFSAlgorithm()
{
}

CFSAlgorithm::~CFSAlgorithm()
{
}

void CFSAlgorithm::CFSCreateProcessTree(int array[], int p_length)
{
    for (int k = 0; k < p_length; k++)
    {
        Node *cfs_TaskNode = new Node();
        cfs_TaskNode->rbt_currentTimeVirtual = array[k];
        RBTInsertion(cfs_TaskNode);
    }
}

void CFSAlgorithm::CFSTaskProcessing()
{
    uint64_t timeStub = cfs_time_quantum_per_task;
    // Check if process tree is empty, non-task, or has any process
    while (root != Nil)
    {
        std::cout << "Time quantum " << timeStub << std::endl;
        // CFS Algorithm
        // Return most left node
        //
        //
        //
        Node *cfs_mostLefTask = RBTReturnMostLeftNode();

        std::cout << "Process of task number " << cfs_mostLefTask->rbt_task_number << " at time quantum " << cfs_mostLefTask->rbt_currentTimeVirtual << std::endl;

        cfs_mostLefTask->rbt_remainTimeVirtual = cfs_mostLefTask->rbt_remainTimeVirtual - cfs_time_quantum_per_task;

        // Check if task finishes at current timequantum
        //
        //
        //
        if (cfs_mostLefTask->rbt_remainTimeVirtual <= 0)
        {
            // Remove that task from process tree
            RBTDeletion(cfs_mostLefTask);
        }
        else
        {
            // Insert task with remaining virtualtime as new Node
            cfs_mostLefTask->rbt_currentTimeVirtual = cfs_mostLefTask->rbt_currentTimeVirtual + cfs_time_quantum_per_task;
            RBTInsertion(cfs_mostLefTask);
        }
        timeStub = (timeStub < STUB_TIME_QUANTUM) ? timeStub + cfs_time_quantum_per_task : STUB_TIME_QUANTUM;
    }
}