#include <bits/stdc++.h>
using namespace std;
vector<string> key = {".;", "?,", "( )", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void Solution(string n, int index, string generate)
{
    if (index == n.size())
    {
        cout << generate << "\n";
        return;
    }
    int val = n[index] - '0';
    for (int i = 0; i < key[val].size(); i++)
    {
        Solution(n, index + 1, generate + key[val][i]);
    }
}

int main()
{
    string n;
    cin >> n;
    Solution(n, 0, "");
    return 0;
}
