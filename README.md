# Multi-Threaded Task Queue

Tasks are pushed onto a queue by the source thread. 
These tasks are processed by a sink thread that applies a threshold to them.

The output from this should be passed to a function that returns a vector of multiples of a provided int.
The sum of this vector is to be displayed.

Later stages may be added to the Task pipeline, bear this in mind.

Create a new branch for your changes and submit a pull request onto master when complete

## Restrictions
* The target OS is Linux
* Don't use any external frameworks or libraries
* Write any unit tests in plain C++11

## TODOs
* Implement a threadsafe BlockingQueue class with push/pop members  
* Implement the get_multiples function (preferably with unit tests)

### Bonus TODOs
* The code is a bit messy, could do with a clean-up
* Is there still a memory leak?
* BlockingQueue should be reusable with other types
* Neither of our classes should be copyable
* num_ints and threshold should be configurable via command line parameters
