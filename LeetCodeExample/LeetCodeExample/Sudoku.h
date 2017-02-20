#pragma once
#include <vector>
using namespace std;

static int maxlength = 9;

struct Cell
{
    int row;
    int col;
    Cell(int r, int c) : row(c), col(c){}
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board);

private:

    bool Sudoku(vector<vector<char>>& board);

    //Methods
    bool CheckBoard(const vector<vector<char>>& board, Cell &point);
    bool CheckCell(int number, Cell point, vector<vector<char>>& board);

    //Helper Methods
    char numberTochar(int number);
};