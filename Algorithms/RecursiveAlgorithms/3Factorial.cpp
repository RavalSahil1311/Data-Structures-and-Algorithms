#include <bits/stdc++.h>
using namespace std;

int Solution(int n)
{
    if (n == 0 | n == 1)
    {
        return n;
    }
    return n * Solution(n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << Solution(n) << "\n";
    return 0;
}
