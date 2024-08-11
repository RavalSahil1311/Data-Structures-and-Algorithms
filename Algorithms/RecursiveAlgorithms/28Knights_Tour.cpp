#include <bits/stdc++.h>
using namespace std;

void Solution(vector<vector<int>> &board, int x, int y, string Knights, int steps)
{
    if (x < 0 || y < 0 || x >= board.size() || y >= board.size() || board[x][y] > 0)
    {
        return;
    }
    else if (steps == board.size() * board.size())
    {
        board[x][y] = steps;
        cout << "Answer\n";
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] < 10)
                {
                    cout << " " << board[i][j] << " ";
                }
                else
                {
                    /* code */
                    cout << board[i][j] << " ";
                }
            }
            cout << "\n";
        }
        return;
    }

    board[x][y] = steps;
    Solution(board, x - 2, y - 1, Knights + to_string(x - 2) + "-" + to_string(y - 1) + ",", steps + 1);
    Solution(board, x - 1, y - 2, Knights + to_string(x - 1) + "-" + to_string(y - 2) + ",", steps + 1);
    Solution(board, x + 1, y - 2, Knights + to_string(x + 1) + "-" + to_string(y - 2) + ",", steps + 1);
    Solution(board, x + 2, y - 1, Knights + to_string(x + 2) + "-" + to_string(y - 1) + ",", steps + 1);
    Solution(board, x + 2, y + 1, Knights + to_string(x + 2) + "-" + to_string(y + 1) + ",", steps + 1);
    Solution(board, x + 1, y + 2, Knights + to_string(x + 1) + "-" + to_string(y + 2) + ",", steps + 1);
    Solution(board, x - 1, y + 2, Knights + to_string(x - 1) + "-" + to_string(y + 2) + ",", steps + 1);
    Solution(board, x - 2, y + 1, Knights + to_string(x - 2) + "-" + to_string(y + 1) + ",", steps + 1);
    board[x][y] = 0;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<int>> board(n, vector<int>(n, 0));
    string Knights = to_string(x) + "-" + to_string(y) + ",";
    Solution(board, x, y, Knights, 1);
    return 0;
}
