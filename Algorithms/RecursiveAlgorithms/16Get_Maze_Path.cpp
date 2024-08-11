#include <bits/stdc++.h>
using namespace std;

vector<string> Solution(int n, int m, int x, int y)
{
    if (x > m || y > n)
    {
        vector<string> ans;
        return ans;
    }
    if (x == n && y == m)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> ans;
    vector<string> ans1 = Solution(n, m, x + 1, y);
    for (int i = 0; i < ans1.size(); i++)
    {
        ans.push_back("h" + ans1[i]);
    }
    vector<string> ans2 = Solution(n, m, x, y + 1);
    for (int i = 0; i < ans2.size(); i++)
    {
        ans.push_back("v" + ans2[i]);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans = Solution(n, m, 1, 1);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
