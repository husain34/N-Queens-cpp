# N-Queens Problem Solver in C++

This project is a C++ implementation of the classic **N-Queens Problem**, which aims to find all the possible arrangements of `N` queens on an `N x N` chessboard such that no two queens attack each other.

## 🧠 Problem Overview

The N-Queens Problem is a well-known combinatorial problem in computer science and mathematics. The challenge is to place `N` queens on a chessboard so that:

- No two queens share the same row.
- No two queens share the same column.
- No two queens share the same diagonal.

## 💡 Approach

This program uses a recursive backtracking algorithm to explore all valid queen placements row by row. It utilizes a `set` of coordinates (`nullCells`) to track all the cells that are under attack and therefore invalid for queen placement.

## 🔧 Features

- Supports any valid `N` value (e.g., 4, 8, 10).
- Optimized tracking of invalid cells using `std::set`.
- Clear and modular code structure with helper functions:
  - `QueenCalc` - Recursive backtracking logic.
  - `PosMoves` - Marks all attacked cells from a queen's position.
  - `AddMoves` - Handles directional movement for attack marking.
  - `isLegal` - Checks if a cell is valid for placing a queen.
  - `NoMoves` - Checks if any moves are left.

## 🖥️ How to Run

1. Clone this repository:
   
   git clone https://github.com/your-username/n-queens-cpp.git
   cd n-queens-cpp
Compile the program using g++ (or any C++ compiler):
    g++ -std=c++11 nqueens.cpp -o nqueens
   
Run the executable:
./nqueens
Enter the number of queens (N) when prompted.

📦 Example:
N Queens:
Enter Number of Queens :
8
Number of Solutions for 8 Queens are : 92
