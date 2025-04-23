#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Function Declarations
int QueenCalc(int size, int n, set<pair<int,int>> nullCells);
bool isLegal(pair<int,int> Coor, set<pair<int,int>> nullCells);
void PosMoves(pair<int,int> Coor, int size, set<pair<int,int>>& nullCells);
void AddMoves(pair<int,int> pos, pair<int,int> loop, int size, set<pair<int,int>>& nullCells);
bool NoMoves(int size, set<pair<int,int>> nullCells);

int main()
{
    int n;
    cout << "N Queens:" << endl;
    cout << "Enter Number of Queens : " << endl;
    cin >> n;

    set<pair<int,int>> nullCells;  // Tracks cells under attack
    int solution = 0;

    // Try placing the first queen in each column of the first row
    for (int i = 0; i < n; i++)
    {
        nullCells.insert({0, i});              // Place queen at (0, i)
        PosMoves({0, i}, n, nullCells);        // Mark all attacked cells
        solution += QueenCalc(n, n - 1, nullCells);  // Recursively place remaining queens
        nullCells.clear();                     // Reset attacked cells for next iteration
    }

    cout << "Number of Solutions for " << n << " Queens are : " << solution << endl;
    return 0;
}

// Recursive function to count valid N-Queens placements
int QueenCalc(int size, int n, set<pair<int,int>> nullCells){
    if(n == 0){
        return 1;  // All queens successfully placed
    }
    if(NoMoves(size, nullCells)){
        return 0;  // No valid position to place next queen
    }
    else{
        int solutions = 0;
        set<pair<int,int>> null;

        // Try placing queen in each column of the current row
        for (int i = 0; i < size; i++)
        {
            if(isLegal({size - n, i}, nullCells)){
                null = nullCells;  // Copy current state
                PosMoves({size - n, i}, size, null);  // Mark attacked positions
                solutions += QueenCalc(size, n - 1, null);  // Recursive call
                null.clear();  // Cleanup
            }
        }
        return solutions;
    }
}

// Checks if the current coordinate is not under attack
bool isLegal(pair<int,int> Coor, set<pair<int,int>> nullCells){
    for (pair<int,int> cell : nullCells) {
        if(cell == Coor){
            return false;
        }
    }
    return true; 
}

// Marks all the positions attacked by a queen at the given coordinate
void PosMoves(pair<int,int> Coor, int size, set<pair<int,int>>& nullCells){

    // Directions: diagonals, rows, and columns
    vector<pair<int, int>> moves = {
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    for(pair<int,int> move : moves)
    {
        AddMoves(Coor, move, size, nullCells);
    }
}

// Adds all positions in a direction that are attacked by a queen
void AddMoves(pair<int,int> pos, pair<int,int> loop, int size, set<pair<int,int>>& nullCells){

    int newRow = pos.first;
    int newCol = pos.second;

    // Keep moving in the given direction until out of bounds
    for (int i = 0; i < size; i++)
    {
        newRow += loop.first;
        newCol += loop.second;

        if (newRow < 0 || newCol < 0 || newRow >= size || newCol >= size){
            break;  // Outside board limits
        }
        else{
            nullCells.insert({newRow, newCol});  // Mark cell as attacked
        }
    }
}

// Checks if there are no valid cells left for placing a queen
bool NoMoves(int size, set<pair<int,int>> nullCells){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(isLegal({i, j}, nullCells)){
                return false;  // Found a legal move
            }
        }
    }
    return true;  // No legal moves found
}
