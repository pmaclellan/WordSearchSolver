# WordSearchSolver
Lab 3 from Optimization Methods (EECE3326). Explores different searching and sorting algorithms to solve word searches.

From project description:

Write a program that solves a word search puzzle. The program reads an n x n grid of letters from
a file and prints out all the words that can be found in the grid. Words can be found in the array
by starting from any letter and reading left, right, up, down, or along any of the four diagonals.
Words can also wrap around the edges of the array. Words must be at least 5 characters long.
The list of k possible words is included in the file dictionary. Several sample word search puzzles
are also provided.
The goal is to find an algorithm that solves this problem that runs as quickly as possible for large
n and k.

Reduce the runtime of your solution to the word search puzzle by using the binarySearch
algorithm to search the dictionary for a word.
The binarySearch algorithm requires that the list of words be in sorted order. Implement
two sorting algorithms and compare their runtimes. One of the sorting algorithms you
implement should be quicksort. Print out the sorted dictionary.
You should turn in a working program based on whichever sorting algorithm is faster. The
other algorithm should be implemented but not called within your code.

*Note: Implementation should be separated from .h files and put into .cpp, but there was some issue with the TA's getting linker errors or something so that's why it isn't.
