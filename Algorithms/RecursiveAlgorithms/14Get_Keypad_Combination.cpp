#include <bits/stdc++.h>
using namespace std;

vector<string> key = {".;", "?,", "( )", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void Solution(vector<string> &ans, string str, int index, string generate)
{
    if (index == str.size())
    {
        ans.push_back(generate);
    }
    int val = (str[index] - '0');
    for (int i = 0; i < key[val].size(); i++)
    {
        Solution(ans, str, index + 1, generate + key[val][i]);
    }
    // if (key[val].size() == 0)
    // {
    //     Solution(key, ans, str, index + 1, generate);
    // }
}

int main()
{
    string str;
    cin >> str;
    vector<string> ans;
    Solution(ans, str, 0, "");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
