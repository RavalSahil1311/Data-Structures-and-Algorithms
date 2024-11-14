#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n), answer;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            answer.push_back(-1);
        }
        else if (s.size() > 0 && s.top() > v[i])
        {
            answer.push_back(s.top());
        }
        else if (s.size() > 0 && s.top() <= v[i])
        {
            while (s.size() > 0 && s.top() <= v[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                answer.push_back(-1);
            }
            else
            {
                answer.push_back(s.top());
            }
        }
        s.push(v[i]);
    }
    for (int i = n - 1; i > -1; i--)
    {
        cout << answer[i] << " ";
    }
    return 0;
}
