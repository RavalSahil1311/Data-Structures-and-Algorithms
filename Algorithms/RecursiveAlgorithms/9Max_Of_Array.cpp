#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int> arr, int index)
{
    if (index == arr.size() - 1)
    {
        return arr[index];
    }

    return max(arr[index], Solution(arr, index + 1));
}

// Whatevver doesn't kills you makes you stronger.

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << Solution(arr, 0);
    return 0;
}
