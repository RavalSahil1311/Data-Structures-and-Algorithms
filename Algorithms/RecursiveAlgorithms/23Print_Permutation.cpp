#include <bits/stdc++.h>
using namespace std;

set<string> s;

void Solution(string n, string answer)
{
    if (n == "")
    {
        // cout << answer << "\n";
        s.insert(answer);
        return;
    }
    for (int index = 0; index < n.size(); index++)
    {
        char c = n[index];
        string new_string = n.substr(0, index) + n.substr(index + 1, n.size() - 1);
        Solution(new_string, answer + c);
    }
}

int main()
{
    string n;
    cin >> n;
    Solution(n, "");
    cout << s.size() << "\n";
    for (auto &&i : s)
    {
        cout << i << "\n";
    }
    return 0;
}
