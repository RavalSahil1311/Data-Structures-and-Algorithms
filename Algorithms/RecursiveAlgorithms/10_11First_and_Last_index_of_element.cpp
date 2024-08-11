#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int> arr, int index, int x)
{
    if (index == arr.size())
    {
        return -1;
    }
    if (arr[index] == x)
    {
        return index + 1;
    }
    return Solution(arr, index + 1, x);
}

int Solution1(vector<int> arr, int index, int x)
{
    if (index == -1)
    {
        return -1;
    }
    if (arr[index] == x)
    {
        return index + 1;
    }
    return Solution(arr, index - 1, x);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << Solution(arr, 0, 5);
    // cout << Solution1(arr, arr.size() - 1, 5);
    return 0;
}
