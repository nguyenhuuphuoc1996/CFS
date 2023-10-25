#ifndef STRUCTURE_H
#define STRUCTURE_H

#define NUMBER_OF_TASKS 6

struct gtask
{
    uint64_t virtualtime;
    void (*job)(const uint64_t p_vitualTime);
};
#endif