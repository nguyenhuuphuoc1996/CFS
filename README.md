This is the simple implementation of CFS
The purpose is to simulate how tasks are perform under multi-task theory
1. CFS Fundamental
The main idea behind the CFS is to maintain balance (fairness) in providing processor time to tasks. This means processes should be given a fair amount of the processor. When the time for tasks is out of balance (meaning that one or more tasks are not given a fair amount of time relative to others), then those out-of-balance tasks should be given time to execute.

To determine the balance, the CFS maintains the amount of time provided to a given task in what's called the virtual runtime. The smaller a task's virtual runtime—meaning the smaller amount of time a task has been permitted access to the processor—the higher its need for the processor. The CFS also includes the concept of sleeper fairness to ensure that tasks that are not currently runnable (for example, waiting for I/O) receive a comparable share of the processor when they eventually need it.

But rather than maintain the tasks in a run queue, as has been done in prior Linux schedulers, the CFS maintains a time-ordered red-black tree (see Figure 1). A red-black tree is a tree with a couple of interesting and useful properties. First, it's self-balancing, which means that no path in the tree will ever be more than twice as long as any other. Second, operations on the tree occur in O(log n) time (where n is the number of nodes in the tree). This means that you can insert or delete a task quickly and efficiently.

2. CFS Implementation
2.1. RedBlackTreeDS
This is a file where the implementation of Red-Black Tree data structure take place. The file provided several API that help to implement CFS algorithm (Insert, Delete...).

2.2. CFSAlgorithm
This is a file where the implementation of CFS algorithm take place.

2.3. ProcessJobFunction
This is a file where to define some job function and their virtual time that need to complete.

Sample output
Time quantum system 1 --- Owner:  process job_1 is calling with virtual time is 1
Time quantum system 2 --- Owner:  process job_2 is calling with virtual time is 2
Time quantum system 3 --- Owner:  process job_2 is calling with virtual time is 1
Time quantum system 4 --- Owner:  process job_3 is calling with virtual time is 4
Time quantum system 1 --- Owner:  process job_4 is calling with virtual time is 5
Time quantum system 2 --- Owner:  process job_6 is calling with virtual time is 5
Time quantum system 3 --- Owner:  process job_3 is calling with virtual time is 3
Time quantum system 4 --- Owner:  process job_4 is calling with virtual time is 4
Time quantum system 1 --- Owner:  process job_6 is calling with virtual time is 4
Time quantum system 2 --- Owner:  process job_3 is calling with virtual time is 2
Time quantum system 3 --- Owner:  process job_5 is calling with virtual time is 7
Time quantum system 4 --- Owner:  process job_4 is calling with virtual time is 3
Time quantum system 1 --- Owner:  process job_6 is calling with virtual time is 3
Time quantum system 2 --- Owner:  process job_3 is calling with virtual time is 1
Time quantum system 3 --- Owner:  process job_5 is calling with virtual time is 6
Time quantum system 4 --- Owner:  process job_4 is calling with virtual time is 2
Time quantum system 1 --- Owner:  process job_6 is calling with virtual time is 2
Time quantum system 2 --- Owner:  process job_5 is calling with virtual time is 5
Time quantum system 3 --- Owner:  process job_4 is calling with virtual time is 1
Time quantum system 4 --- Owner:  process job_6 is calling with virtual time is 1
Time quantum system 1 --- Owner:  process job_5 is calling with virtual time is 4
Time quantum system 2 --- Owner:  process job_5 is calling with virtual time is 3
Time quantum system 3 --- Owner:  process job_5 is calling with virtual time is 2
Time quantum system 4 --- Owner:  process job_5 is calling with virtual time is 1

3. References:
3.1. https://developer.ibm.com/tutorials/l-completely-fair-scheduler/
3.2. https://en.wikipedia.org/wiki/Completely_Fair_Scheduler
