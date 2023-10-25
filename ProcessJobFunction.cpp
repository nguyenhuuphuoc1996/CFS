#include "ProcessJobFunction.h"

void job_1(const uint64_t p_vitualTime);
void job_2(const uint64_t p_vitualTime);

void job_3(const uint64_t p_vitualTime);
void job_4(const uint64_t p_vitualTime);

void job_5(const uint64_t p_vitualTime);
void job_6(const uint64_t p_vitualTime);

ProcessJobFunction::ProcessJobFunction()
{
    // No need constructor
}

ProcessJobFunction::~ProcessJobFunction()
{
    // No need destructor
}

void ProcessJobFunction::taskinit()
{
    taskTable[0].virtualtime = 1;
    taskTable[0].job = job_1;
    taskTable[1].virtualtime = 2;
    taskTable[1].job = job_2;
    taskTable[2].virtualtime = 4;
    taskTable[2].job = job_3;
    taskTable[3].virtualtime = 5;
    taskTable[3].job = job_4;
    taskTable[4].virtualtime = 7;
    taskTable[4].job = job_5;
    taskTable[5].virtualtime = 5;
    taskTable[5].job = job_6;
}

// Need update here for robustnees properties
void ProcessJobFunction::runtask()
{
    taskinit();
    CFSTaskProcessing(taskTable, NUMBER_OF_TASKS);
}

void job_1(const uint64_t p_vitualTime)
{
    std::cout << " process job_1 is calling with virtual time is " << p_vitualTime << std::endl;
}
void job_2(const uint64_t p_vitualTime)
{
    std::cout << " process job_2 is calling with virtual time is " << p_vitualTime << std::endl;
}
void job_3(const uint64_t p_vitualTime)
{
    std::cout << " process job_3 is calling with virtual time is " << p_vitualTime << std::endl;
}
void job_4(const uint64_t p_vitualTime)
{
    std::cout << " process job_4 is calling with virtual time is " << p_vitualTime << std::endl;
}
void job_5(const uint64_t p_vitualTime)
{
    std::cout << " process job_5 is calling with virtual time is " << p_vitualTime << std::endl;
}
void job_6(const uint64_t p_vitualTime)
{
    std::cout << " process job_6 is calling with virtual time is " << p_vitualTime << std::endl;
}
