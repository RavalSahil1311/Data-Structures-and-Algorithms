#include <bits/stdc++.h>
using namespace std;

void Solution(vector<int> arr, int index, int x, vector<int> &ans)
{
    if (index == arr.size())
    {
        return;
    }
    if (arr[index] == x)
    {
        ans.push_back(index + 1);
    }
    Solution(arr, index, x, ans);
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
    vector<int> ans;
    Solution(arr, 0, 3, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
