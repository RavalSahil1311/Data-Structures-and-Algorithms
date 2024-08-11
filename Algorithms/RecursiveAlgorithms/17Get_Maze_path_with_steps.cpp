#include <bits/stdc++.h>
using namespace std;

vector<string> Solution(int x, int y, int n, int m)
{
    if (x > n || y > n)
    {
        vector<string> ans;
        return ans;
    }
    if (x == n && y == n)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> ans;

    for (int i = 1; i <= m - y; i++)
    {
        vector<string> ans1 = Solution(x, y + i, n, m);
        for (int j = 0; j < ans1.size(); j++)
        {
            ans.push_back("h" + to_string(i) + ans1[j]);
        }
    }
    for (int i = 1; i <= n - x; i++)
    {
        vector<string> ans1 = Solution(x + i, y, n, m);
        for (int j = 0; j < ans1.size(); j++)
        {
            ans.push_back("v" + to_string(i) + ans1[j]);
        }
    }
    for (int i = 1; i <= n - x && m - y; i++)
    {
        vector<string> ans1 = Solution(x + i, y + i, n, m);
        for (int j = 0; j < ans1.size(); j++)
        {
            ans.push_back("d" + to_string(i) + ans1[j]);
        }
    }

    return ans;
}

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<string> ans = Solution(1, 1, n, m);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
