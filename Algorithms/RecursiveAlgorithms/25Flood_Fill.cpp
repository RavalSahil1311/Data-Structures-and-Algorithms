#include <bits/stdc++.h>
using namespace std;

void Solution(int x, int y, vector<string> Maze, vector<vector<int>> vis, string answer)
{
    if (x == Maze.size() - 1 && y == Maze.size() - 1)
    {
        cout << answer << "\n";
        return;
    }
    if (x >= Maze.size() || y >= Maze.size() || x < 0 || y < 0)
    {
        return;
    }

    if (Maze[x][y] == '1' || vis[x][y] == 1)
    {
        return;
    }

    vis[x][y] = 1;
    Solution(x + 1, y, Maze, vis, answer + "D");
    Solution(x - 1, y, Maze, vis, answer + "U");
    Solution(x, y + 1, Maze, vis, answer + "R");
    Solution(x, y - 1, Maze, vis, answer + "L");
    vis[x][y] = 0;
}

int main()
{
    int n;
    cin >> n;
    vector<string> Maze(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Maze[i];
    }
    cout << Maze.size() << "\n";
    vector<vector<int>> vis(n, vector<int>(n, 0));
    Solution(0, 0, Maze, vis, "");
    return 0;
}
