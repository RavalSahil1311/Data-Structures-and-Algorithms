#include <bits/stdc++.h>
using namespace std;

void Solution(int n)
{
    if (n == 0)
        return;
    cout << "Pre " << n << "\n";
    Solution(n - 1);
    cout << "In " << n << "\n";
    Solution(n - 1);
    cout << "Post " << n << "\n";
}

int main()
{
    int n;
    cin >> n;
    Solution(n);
    return 0;
}
