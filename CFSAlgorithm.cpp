#include "CFSAlgorithm.h"

CFSAlgorithm::CFSAlgorithm()
{
}

CFSAlgorithm::~CFSAlgorithm()
{
}

void CFSAlgorithm::CFSCreateProcessTree(uint64_t array[], uint64_t p_length)
{
    for (int k = 0; k < p_length; k++)
    {
        Node *cfs_TaskNode = new Node();
        cfs_TaskNode->rbt_currentTimeVirtual = array[k];
        cfs_TaskNode->rbt_remainTimeVirtual = array[k];
        cfs_TaskNode->rbt_task_number = k + 1;
        RBTInsertion(cfs_TaskNode);
    }
    cfs_time_quantum_per_task = (uint64_t)STUB_TIME_QUANTUM / p_length;
    cfs_time_quantum_per_task = (cfs_time_quantum_per_task > 0) ? cfs_time_quantum_per_task : MINIMUM_TIME_QUANTUM;
}

void CFSAlgorithm::CFSTaskProcessing()
{
    uint64_t timeStub = cfs_time_quantum_per_task;
    // Check if process tree is empty, non-task, or has any process
    while (T != Nil)
    {
        std::cout << "Time quantum " << timeStub;
        // CFS Algorithm
        // Return most left node
        //
        //
        //
        Node *cfs_mostLefTask = RBTReturnMostLeftNode();

        std::cout << " --- Process of task number " << cfs_mostLefTask->rbt_task_number << " --- with current Virtual Time " << cfs_mostLefTask->rbt_remainTimeVirtual << std::endl;

        // Remain virtualtime after a divided of quantum time
        //
        //
        //
        cfs_mostLefTask->rbt_remainTimeVirtual = cfs_mostLefTask->rbt_remainTimeVirtual - cfs_time_quantum_per_task;

        // Check if task finishes at current timequantum
        //
        //
        //
        // Remove that task from process tree
        RBTDeletion(cfs_mostLefTask);
        if (cfs_mostLefTask->rbt_remainTimeVirtual <= 0)
        {
            // Task has finished
            delete cfs_mostLefTask;
        }
        else
        {
            // Insert task with remaining virtualtime as new Node
            //
            //
            //
            Node *cfs_newNode = new Node();
            cfs_newNode->rbt_currentTimeVirtual = cfs_mostLefTask->rbt_currentTimeVirtual + cfs_time_quantum_per_task;
            cfs_newNode->rbt_remainTimeVirtual = cfs_mostLefTask->rbt_remainTimeVirtual;
            cfs_newNode->rbt_task_number = cfs_mostLefTask->rbt_task_number;
            // Insert new node
            //
            //
            RBTInsertion(cfs_newNode);
        }

        // Next quantum time
        timeStub = (timeStub < STUB_TIME_QUANTUM) ? timeStub + cfs_time_quantum_per_task : cfs_time_quantum_per_task;
    }
}
