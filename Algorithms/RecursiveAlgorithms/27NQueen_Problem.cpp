#include <bits/stdc++.h>
using namespace std;

bool isSafePlace(vector<vector<int>> board, int row, int col)
{
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void Solution(vector<vector<int>> board, string queen, int row)
{
    if (row == board.size())
    {
        cout << "ANSWER:\n";
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j])
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << "\n";
        }
        return;
    }

    for (int col = 0; col < board.size(); col++)
    {
        if (isSafePlace(board, row, col))
        {
            board[row][col] = 1;
            Solution(board, queen + to_string(row) + "-" + to_string(col) + ",", row + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    string queen = "";
    Solution(board, queen, 0);
    return 0;
}
