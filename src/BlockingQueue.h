#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include "Task.h"

#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>

class BlockingQueue
{
public:
    BlockingQueue();

    // Push a task ptr onto the queue
    void push(std::unique_ptr<Task> t);

    // Return the first element in the queue
    std::unique_ptr<Task> pop();

    // Disable copy constructor
    BlockingQueue(const BlockingQueue&) = delete;

private:
    std::queue<std::unique_ptr<Task>> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cond;
}; 

#endif
