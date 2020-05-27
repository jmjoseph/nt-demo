#ifndef TASK_H
#define TASK_H

class Task
{
public:
    Task(int val,
         bool sentinel = false)
    {
        m_val = val;
        m_sent = sentinel;
    }

    int m_val;
    int m_sent;
    
    // Disable copy constructor
    Task(const Task&) = delete;
};
#endif
