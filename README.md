Dictionary Implementations and Reverse Polish Notation (RPN) Calculator

This repository contains two C programs demonstrating:

- Dictionary Implementations: Array-based, linked list-based, and hash table-based dictionaries for storing and fetching data efficiently.
- Reverse Polish Notation (RPN) Calculator: A stack-based calculator that evaluates arithmetic expressions in Reverse Polish Notation.

Project 1: Dictionary Implementations
Overview
This program implements and benchmarks three dictionary data structures:

Array-Based Dictionary
Linked List-Based Dictionary
Hash Table-Based Dictionary
The program measures the store and fetch times for each implementation and compares their theoretical and actual performance.


Project 2: Reverse Polish Notation (RPN) Calculator
Overview
This program evaluates arithmetic expressions in Reverse Polish Notation (RPN) using a stack.

Features
Supports basic arithmetic operations: +, -, x, /.
Handles floating-point numbers with error detection.
Implements a custom stack with push and pop operations.

Example:
To evaluate the expression (3 + 5) * 2 in RPN:
Input: 
./rpn_calculator 3 5 + 2 x
Output:
The total is 16


