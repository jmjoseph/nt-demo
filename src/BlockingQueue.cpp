#include "BlockingQueue.h"

#include <iostream>

BlockingQueue::BlockingQueue()
{
}

void BlockingQueue::push(std::unique_ptr<Task> t)
{
    // Lock the mutex while the queue is modified
    std::unique_lock<std::mutex> lock(m_mutex);
    m_queue.push(std::move(t));
    
    // Unlock and notify any process (pop()) that is waiting 
    lock.unlock();
    m_cond.notify_one();
}

std::unique_ptr<Task> BlockingQueue::pop()
{
    // Lock the mutex and wait until the queue is not empty
    std::unique_lock<std::mutex> lock(m_mutex);
    while (m_queue.empty())
    {
        m_cond.wait(lock);
    }

    // Get pointer to task before it is popped off
    std::unique_ptr<Task> returnValue = std::move(m_queue.front());
    m_queue.pop();

    lock.unlock();
    return returnValue;
}
