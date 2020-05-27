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
> I might have cheated here. I'm using Catch2's single header library for unit testing
* Write any unit tests in plain C++11

## TODOs
* Implement a threadsafe BlockingQueue class with push/pop members  
* Implement the get_multiples function (preferably with unit tests)

### Bonus TODOs
* The code is a bit messy, could do with a clean-up
> Reorganized, renamed, and did some cleaning.
* Is there still a memory leak?
> I believe I addressed this with deleting the raw pointer to Task
* BlockingQueue should be reusable with other types
> I did NOT do a template implementation.
* Neither of our classes should be copyable
> Done.
* num_ints and threshold should be configurable via command line parameters
> Done. How is there still not a standard/native library for this?!

## Instructions
1. Download entire project.
2. Navigate into source directory and create build directory.
```
$ cd jeremy-joseph-interview
$ mkdir build
$ cd build
```
3. Build the application using CMake. 
  Download and install [CMake](http://www.cmake.org) if necessary.
```
$ cmake ..
$ cmake --build .
```
4. In the build directory, run the application.
```
$ ./interview_test [number of integers] [threshold]
```
### Unit Testing
To run some example unit tests, run the following command in the build directory.
```
$ ./test_modifiers -s
```
