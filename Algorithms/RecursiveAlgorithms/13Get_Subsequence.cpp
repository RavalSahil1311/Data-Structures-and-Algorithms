#include <bits/stdc++.h>
using namespace std;

vector<string> Solution(string s)
{
    if (s.size() == 1)
    {
        vector<string> ans;
        ans.push_back("");
        ans.push_back(s);
        return ans;
    }

    char ch = s[0];
    string s1 = s.substr(1, s.size());
    vector<string> half_ans = Solution(s1);
    vector<string> ans;
    for (int i = 0; i < half_ans.size(); i++)
    {
        ans.push_back("" + half_ans[i]);
        ans.push_back(ch + half_ans[i]);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> ans = Solution(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
