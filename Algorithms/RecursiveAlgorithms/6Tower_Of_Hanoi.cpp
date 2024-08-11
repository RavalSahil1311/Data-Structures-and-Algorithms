#include <bits/stdc++.h>
using namespace std;

void Solution(int n, int tid1, int tid2, int tid3)
{
    if (n == 0)
        return;
    Solution(n - 1, tid1, tid3, tid2);
    cout << tid1 << " " << tid2 << "\n";
    // cout << n << " " << tid1 << " " << tid2 << "\n";
    Solution(n - 1, tid3, tid2, tid1);
}

int main()
{
    int n;
    cin >> n;
    cout << pow(2,n) - 1 << "\n";
    Solution(n, 1, 3, 2);
    return 0;
}
