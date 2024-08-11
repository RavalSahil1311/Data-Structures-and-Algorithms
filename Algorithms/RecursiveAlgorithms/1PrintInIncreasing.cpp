#include <bits/stdc++.h>
using namespace std;

void Solution(int n)
{
    if (n < 1)
    {
        return;
    }
    Solution(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    Solution(n);
    return 0;
}
