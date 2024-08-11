#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
void Solution(int n, int k, string path)
{
    if (n <= 0)
    {
        ans.push_back(path);
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            Solution(n - i, k, path + to_string(i));
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    Solution(n, k, "");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
