#include <bits/stdc++.h>
using namespace std;

void Solution(string str, string ans)
{
    if (str == "")
    {
        cout << ans << "\n";
        return;
    }
    char c = str[0];
    string substr = str.substr(1);
    Solution(substr, ans + "");
    Solution(substr, ans + c);
}

int main()
{
    string n;
    cin >> n;
    Solution(n, "");
    return 0;
}
