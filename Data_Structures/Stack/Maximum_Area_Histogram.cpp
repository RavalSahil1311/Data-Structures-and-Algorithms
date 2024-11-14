#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<pair<int, int>> sl, sr;
    vector<int> v(n), nsl, nsr;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (sl.size() == 0)
        {
            nsl.push_back(-1);
        }
        else if (sl.size() > 0 && sl.top().first <= v[i])
        {
            nsl.push_back(sl.top().second);
        }
        else
        {
            while (sl.size() > 0 && sl.top().first > v[i])
            {
                sl.pop();
            }
            if (sl.size() == 0)
            {
                nsl.push_back(-1);
            }
            else
            {
                nsl.push_back(sl.top().second);
            }
        }
        sl.push({v[i], i});
    }
    for (int i = n - 1; i > -1; i--)
    {
        if (sr.size() == 0)
        {
            nsr.push_back(n);
        }
        else if (sr.size() > 0 && sr.top().first <= v[i])
        {
            nsr.push_back(sr.top().second);
        }
        else
        {
            while (sr.size() > 0 && sr.top().first > v[i])
            {
                sr.pop();
            }
            if (sr.size() == 0)
            {
                nsr.push_back(n);
            }
            else
            {
                nsr.push_back(sr.top().second);
            }
        }
        sr.push({v[i], i});
    }
    reverse(nsr.begin(), nsr.end());
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if ((nsr[i] - nsl[i] - 1) * v[i] > max)
        {
            max = (nsr[i] - nsl[i] - 1) * v[i];
        }
    }
    cout << max << "\n";
    return 0;
}
