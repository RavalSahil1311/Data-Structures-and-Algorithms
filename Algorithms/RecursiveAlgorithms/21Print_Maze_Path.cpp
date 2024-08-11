#include <bits/stdc++.h>
using namespace std;

void Solution(int x, int y, int n, int m, string generate)
{
    if (x > n || y > m)
    {
        return;
    }
    if (x == n && y == m)
    {
        cout << generate << "\n";
        return;
    }
    Solution(x + 1, y, n, m, generate + "h");
    Solution(x, y + 1, n, m, generate + "v");
    Solution(x + 1, y + 1, n, m, generate + "d");
}

int main()
{
    int n, m;
    cin >> n >> m;
    Solution(1, 1, n, m, "");
    return 0;
}
