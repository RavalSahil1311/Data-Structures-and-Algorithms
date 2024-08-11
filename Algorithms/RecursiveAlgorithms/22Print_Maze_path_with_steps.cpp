#include <bits/stdc++.h>
using namespace std;

void Solution(int x, int y, int n, int m, string generate)
{
    if (x > n || y > m)
    {
        return;
    }
    if (n == x && m == y)
    {
        cout << generate << "\n";
        return;
    }
    for (int i = 1; i <= n - x; i++)
    {
        Solution(x + i, y, n, m, generate + "h" + to_string(i));
    }
    for (int i = 1; i <= m - y; i++)
    {
        Solution(x, y + i, n, m, generate + "v" + to_string(i));
    }
    for (int i = 1; i <= m - y && n - x; i++)
    {
        Solution(x + i, y + i, n, m, generate + "d" + to_string(i));
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    Solution(1, 1, n, m, "");
    return 0;
}
