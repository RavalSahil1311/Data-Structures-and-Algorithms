#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<pair<int, int>> s;
    vector<int> v(n), answer;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            answer.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > v[i])
        {
            answer.push_back(s.top().second);
        }
        else
        {
            while (s.size() > 0 && s.top().first <= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                answer.push_back(-1);
            }
            else
            {
                answer.push_back(s.top().second);
            }
        }
        s.push({v[i], i - 1});
    }
    for (int i = 0; i < n; i++)
    {
        cout << i - answer[i] << " ";
    }

    return 0;
}
