#include "Sudoku.h"

void Solution::solveSudoku(vector<vector<char>>& board)
{
    if (Sudoku(board))
        printf("Found solution.\n");
    else
        printf("Failed.\n");
}

bool Solution::Sudoku(vector<vector<char>>& board)
{
    
    Cell point(-1, -1);

    // Check board 
    if (CheckBoard(board, point))
    {
        for (int number = 1; number < 10; ++number)
        {
            // Check, does this number conflict 
            if (CheckCell(number, point, board))
            {
                // Insert number
                board[point.row][point.col] = numberTochar(number);

                // Move next step
                if (Sudoku(board))
                    return true;

                // Insert number was worng, reset.
                board[point.row][point.col] = '.';
            }
        }
        return false;
    }
    return true;
}


bool Solution::CheckBoard(const vector<vector<char>>& board, Cell &point)
{
    for (int row = 0; row < maxlength; ++row)
    {
        for (int col = 0; col < maxlength; ++col)
        {
            if (board[row][col] == '.')
            {
                point.row = row;
                point.col = col;
                return true;
            }
        }
    }

    return false;
}

bool Solution::CheckCell(int number, Cell point, vector<vector<char>>& board)
{
    int r = point.row, c = point.col;
    int subr = -1, subc = -1;

    for (int i = 0; i < maxlength; ++i)
    {
        char num[1];
        if (board[i][c] == numberTochar(number))
            return false;

        if (board[r][i] == numberTochar(number))
            return false;
    }

    if (0 <= r && r < 3)
        subr = 0;
    else if (3 <= r && r < 6)
        subr = 3;
    else
        subr = 6;

    if (0 <= c && c < 3)
        subc = 0;
    else if (3 <= c && c < 6)
        subc = 3;
    else 
        subc = 6;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[subr + j][subc + i] == numberTochar(number))
                return false;
        }
    }
    return true;
}

char Solution::numberTochar(int number)
{
    return number + 48;
}
