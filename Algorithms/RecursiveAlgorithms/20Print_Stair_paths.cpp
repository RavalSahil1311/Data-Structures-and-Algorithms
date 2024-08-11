#include <bits/stdc++.h>
using namespace std;

void Solution(int n, int k, string generate)
{
    if (n == 0)
    {
        cout << generate << "\n";
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        if (n - i > -1)
        {
            Solution(n - i, k, generate + to_string(i));
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    Solution(n, k, "");
    return 0;
}
