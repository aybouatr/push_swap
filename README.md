# push_swap

**42 Project**: `push_swap` - A sorting algorithm project where the goal is to sort a stack of integers using the minimum number of operations.

## Project Overview

The `push_swap` project aims to develop a sorting algorithm to sort a stack of integers using only a limited set of operations. The challenge is to implement this sorting with a minimal number of operations, focusing on the efficiency of the algorithm rather than simply writing a working solution. 

In this project, you must write a program that takes a set of integers as arguments and sorts them using the following operations:
- `sa`: Swap the top two elements of stack A.
- `sb`: Swap the top two elements of stack B.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa`: Push the top element of stack B to stack A.
- `pb`: Push the top element of stack A to stack B.
- `ra`: Rotate stack A (move the top element to the bottom).
- `rb`: Rotate stack B.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra`: Reverse rotate stack A (move the bottom element to the top).
- `rrb`: Reverse rotate stack B.
- `rrr`: Perform `rra` and `rrb` simultaneously.

## Features

- **Sorting Algorithm**: Efficiently sorts an integer stack with minimal operations.
- **Optimized Performance**: Minimizes the number of operations for large inputs.
- **Edge Case Handling**: Correctly handles edge cases, including single-element stacks and already sorted stacks.
- **Operations Compliance**: Implements the specific operations required for this project as defined in the constraints.
- **Visualization**: Optionally, users can visualize the sorting process using additional tools or code for educational purposes.

## Getting Started

To begin using the `push_swap` program, clone the repository to your local machine:

```bash
git clone https://github.com/aybouatr/push_swap.git
