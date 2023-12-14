# Linear Transformation Matrix Segmentation Tree

## Problem Description

This C++ project involves implementing a data structure to efficiently handle linear transformations on 2D points over multiple time instants. The goal is to determine the final coordinates of a point given its initial coordinates, birth time, death time, and a sequence of linear transformations applied at different time instants.

## Matrix Representations

The transformations are represented by a sequence of n 2 x 2 matrices A₁, A₂, ..., Aₙ. Initially, all matrices are the identity matrix. Two types of operations can be performed:

1. **Update Operation**: Choose a time instant 𝑖 and replace the matrix Aᵢ with a valid matrix 𝐵.

2. **Query Operation**: Specify birth 𝑡₀ and death 𝑡_d instants, along with initial coordinates 𝑥 and 𝑦 of a point at birth. Determine the final coordinates of the point at its disappearance.

## Segmentation Tree

The solution involves implementing a Segmentation Tree (segtree) data structure. This structure efficiently handles both update and query operations. It precomputes solutions for subarrays to facilitate quick execution of transformations and coordinate calculations.

## Implementation

1. **Matrix Operations**: Implement matrix multiplication and exponentiation to efficiently apply linear transformations.

2. **Segmentation Tree**: Develop a segtree to store and update the matrix sequence. Each node in the tree represents a segment of the time instants, and the matrices associated with these segments are computed and updated dynamically.

3. **Update Operation**: Allow users to update a specific time instant 𝑖 with a valid matrix 𝐵.

4. **Query Operation**: Enable users to query the final coordinates of a point given birth and death instants, along with initial coordinates.

## Compilation and Execution

Compile the source code using a C++ compiler, and execute the program to perform update and query operations on the linear transformations.

## License

This project is distributed under the MIT license. Feel free to use and modify the code, respecting the terms of the license.
