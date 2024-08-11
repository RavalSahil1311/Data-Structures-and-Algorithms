#include <bits/stdc++.h>
using namespace std;

void Solution(string str, string answer)
{
    if (str == "")
    {
        cout << answer << "\n";
        return;
    }
    else if (str.size() == 1)
    {
        if (str[0] == '0')
        {
            return;
        }
        else
        {
            int chv = str[0] - '0';
            cout << answer + (char)('a' + chv - 1) << "\n";
        }
    }
    else
    {
        char c = str[0];
        string new_string = str.substr(1);
        if (str[0] == '0')
        {
            return;
        }
        else
        {
            int chv = str[0] - '0';
            Solution(new_string, answer + (char)('a' + chv - 1));
        }
        string c12 = str.substr(0, 2);
        new_string = str.substr(2);
        int number = stoi(c12);
        if (number <= 26)
        {
            Solution(new_string, answer + (char)('a' + number - 1));
        }
    }
}

int main()
{
    string str;
    cin >> str;
    Solution(str, "");
    return 0;
}
