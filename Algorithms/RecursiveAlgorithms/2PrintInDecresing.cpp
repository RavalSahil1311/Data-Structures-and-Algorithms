#include <bits/stdc++.h>
using namespace std;

void Solution(int n)
{
    if (n < 1)
    {
        return;
    }
    cout << n << " ";
    Solution(n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    Solution(n);
    return 0;
}
