#include <bits/stdc++.h>
using namespace std;

void Solution(vector<int> arr, int index)
{
    if (index >= arr.size())
    {
        return;
    }

    cout << arr[index] << "\n";
    Solution(arr, index + 1);
    cout << arr[index] << "\n";
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
    Solution(arr, 0);

    return 0;
}
