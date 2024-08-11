#include <bits/stdc++.h>
using namespace std;

int Solution(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * Solution(x, n - 1);
}

int SolutionLog(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    int pow = SolutionLog(x, n / 2);
    if (n & 1)
    {
        return x * pow * pow;
    }
    else
    {
        return pow * pow;
    }
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << SolutionLog(x, n) << "\n";
    return 0;
}
