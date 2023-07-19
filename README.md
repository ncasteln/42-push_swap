# push_swap

push_swap is a project developed for 42 Heilbroon School.

## Keywords
C programming - sorting algorithm - time complexity - data structure - abstract data type - stack - LIFO - circular linked lists - radix sort - mapping

## Subject
The goal of this project is to efficiently sort a given set of integers in ascending order using 2 stacks as Abstract Data Types, while minimizing the number of operations.

## Brief Explanation
The code can be divided into three main sections:

### 1. Input Parsing
Ensure the consistency of the input through meticulous validation functions. The project requirements specify that duplicates are not allowed. If the input is invalid at any step, the allocated memory is freed, and an error is returned.

### 2. Data Structure & Operations
I implemented circular linked lists to handle the list of integers. To fulfill the project requirements, the following operations are implemented: pop, push, rotate (shift up), reverse rotate (shift down), and swap of two elements. These operations serve as the foundation to sort the integers.

### 3. Adapting a Sorting Algorithm
In adapting the sorting algorithm for this project, I have chosen to implement the Radix Sort algorithm. To optimize the sorting process while staying within the constraints of the 2-stack requirement, I used bitwise operations and developed an indexing-based mapping approach.

## Try it Out
To get started with push_swap, follow these steps:

1. Clone the repository:
