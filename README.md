# push_swap

push_swap is a project developed for 42 Heilbroon School.

## Keywords
C programming - sorting algorithm - time complexity - data structure - abstract data type - stack - LIFO - circular linked lists - radix sort - mapping

## Subject
The goal of this project is to efficiently sort a given set of integers in ascending order using 2 stacks as Abstract Data Types, while minimizing the number of operations. For more info about the requirements, take a look at the [subject](en.subject.pdf) contained in this repo.

## Brief Explanation
The code can be divided into three main sections:

### 1. Input Parsing
Ensure the consistency of the input through meticulous validation functions. The project requirements specify that duplicates are not allowed. If the input is invalid at any step, the allocated memory is freed, and an error is returned.

### 2. Data Structure & Operations
I implemented circular linked lists to handle the list of integers. To fulfill the project requirements, the following operations are implemented: pop, push, rotate (shift up), reverse rotate (shift down), and swap of two elements. These operations serve as the foundation to sort the integers.

### 3. Adapting a Sorting Algorithm
In adapting the sorting algorithm for this project, I have chosen to implement the Radix Sort algorithm. To optimize the sorting process while staying within the constraints of the 2-stack requirement, I used bitwise operations and developed an indexing-based mapping approach.

### 4. Leaks free
Like in any other project of 42, the memory allocated by `malloc()` has to be properly sfreed. No leaks are tolerated. In this project I checked the leaks using [valgrind](https://valgrind.org/) and `system("leaks <program-name>")`

---

## Try it out
1. Clone the repository:
```
git clone https://github.com/ncasteln/42-push_swap
```
2. Navigate to the `push_swap` directory and `make` program:
```
cd 42-push_swap
make
```
3. Execute it, passing a random amount of number:
```
./push_swap <random-numbers>
```
4. Accordingly on the input you choose, the program should either throw an error in case of invalid arguments, print the moves to sort the numbers or nothing if the numbers are already sorted.
> **Note:** Since it's not specified by the subject, the sorted numbers are not explicitely printed.

