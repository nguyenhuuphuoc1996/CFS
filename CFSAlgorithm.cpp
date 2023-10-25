#include "CFSAlgorithm.h"

CFSAlgorithm::CFSAlgorithm()
{
}

CFSAlgorithm::~CFSAlgorithm()
{
}

void CFSAlgorithm::CFSCreateProcessTree(uint64_t p_virtualTime, uint64_t p_task_number)
{
    Node *cfs_TaskNode = new Node();
    cfs_TaskNode->rbt_currentTimeVirtual = p_virtualTime;
    cfs_TaskNode->rbt_remainTimeVirtual = p_virtualTime;
    cfs_TaskNode->rbt_task_number = p_task_number;
    RBTInsertion(cfs_TaskNode);
}

void CFSAlgorithm::CFSTaskProcessing(gtask p_taskTable[], uint64_t p_length)
{
    uint64_t timeStub, task_index;

    cfs_time_quantum_per_task = (uint64_t)STUB_TIME_QUANTUM / p_length;
    cfs_time_quantum_per_task = (cfs_time_quantum_per_task > 0) ? cfs_time_quantum_per_task : MINIMUM_TIME_QUANTUM;
    timeStub = cfs_time_quantum_per_task;

    // Create process tree
    for (task_index = 0; task_index < p_length; task_index++)
    {
        CFSCreateProcessTree(p_taskTable[task_index].virtualtime, task_index);
    }

    // Check if process tree is empty, non-task, or has any process
    while (T != Nil)
    {
        std::cout << "Time quantum system " << timeStub << " --- "
                  << "Owner: ";
        // CFS Algorithm
        // Return most left node
        //
        //
        //
        Node *cfs_mostLefTask = RBTReturnMostLeftNode();

        // std::cout << " --- Process of task number " << cfs_mostLefTask->rbt_task_number << " --- with current Virtual Time " << cfs_mostLefTask->rbt_remainTimeVirtual << std::endl;
        p_taskTable[cfs_mostLefTask->rbt_task_number].job(cfs_mostLefTask->rbt_remainTimeVirtual);

        // Remain virtualtime after a divided of quantum time
        //
        //
        //
        if (cfs_mostLefTask->rbt_remainTimeVirtual >= cfs_time_quantum_per_task)
        {
            // Avoid negative
            cfs_mostLefTask->rbt_remainTimeVirtual = cfs_mostLefTask->rbt_remainTimeVirtual - cfs_time_quantum_per_task;
        }
        else
        {
            cfs_mostLefTask->rbt_remainTimeVirtual = 0;
        }

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
