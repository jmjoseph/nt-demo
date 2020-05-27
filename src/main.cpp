#include "Task.h"
#include "BlockingQueue.h"
#include "modifiers.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <thread>


// Loads the queue with Tasks, and marks the last Task as a sentinel
void source_thread_func(BlockingQueue &bq, int num_ints)
{
    for (int i = 1; i <= num_ints; i++)
    {
        std::unique_ptr<Task> task(new Task(i, i == num_ints));
        
        //std::cout<<"Pushing "<<task->m_val<<std::endl;
        bq.push(std::move(task));
    }
}

// Processes all Tasks on the queue, breaking when it reaches the sentinel
void sink_thread_func(BlockingQueue &bq, std::vector<int> &vec, int threshold)
{
    while(true)
    {
        std::unique_ptr<Task> t = bq.pop();
        Task *task = t.release();

        //std::cout<<"Popping "<<task->m_val<<std::endl;
        
        vec.push_back(task->m_val >= threshold ? task->m_val : 0);

        if (task->m_sent)
        {
            delete task;
            break;
        }

        // Manually delete since we're no longer using unique_ptr
        delete task;
    }
}

int main(int argc, char **argv)
{
    int threshold, num_ints;

    // Parse command line arguments
    if (argc == 3)
    {
        std::istringstream second(argv[2]);
    
        // Threshold should be a positive integer
        if (!(second >> threshold) || threshold <= 0)
        {
            std::cout<<"Threshold value invalid."<<std::endl;
            std::cout<<"Exiting program...\n"<<std::endl;
            exit(1);
        }

        std::istringstream first(argv[1]);
    
        // Number of ints should be at least equal to threshold
        if (!(first >> num_ints) || num_ints < threshold)
        {
            std::cout<<"Number of integers should be at least equal to threshold."<<std::endl;
            std::cout<<"Exiting program...\n"<<std::endl;
            exit(1);
        }
    }
    else
    {
        std::cout<<"\nUSAGE:"<<std::endl;
        std::cout<<argv[0]<<" [number of integers] [threshold]\n"<<std::endl;
        exit(1);
    }
   
    //std::cout<<"INPUT: "<<num_ints<<" "<<threshold<<std::endl; 

    BlockingQueue q;
    std::vector<int> t;

    // Create thread processes for source/sink
    std::thread source_thread(source_thread_func, std::ref(q), num_ints);
    std::thread sink_thread(sink_thread_func, std::ref(q), std::ref(t), threshold);

    // Sync threads before proceeding
    source_thread.join();
    sink_thread.join();

    // get_multiples should return a vector of the values in t that are integer multiples of threshold
    std::vector<int> m = get_multiples(t, threshold);

    //std::cout<<"Vectors t & m are sizes: "<<t.size()<<" & "<<m.size()<<std::endl;
    int sum = 0;
    for (int i = 0; i < m.size(); i++)
    {
        //std::cout<<m[i]<<std::endl;
        sum += m[i];
    }

    std::cout << "Sum of multiples greater than or equal to threshold: " << sum << std::endl;
}
