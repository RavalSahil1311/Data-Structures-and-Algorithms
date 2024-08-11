#include <bits/stdc++.h>
using namespace std;

void Solution(vector<int> v, int TargetSum, vector<int> answer, int index, int CurrentSum)
{
    if (CurrentSum > TargetSum || index >= v.size())
    {
        return;
    }
    if (CurrentSum == TargetSum)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }
    Solution(v, TargetSum, answer, index + 1, CurrentSum);
    answer.push_back(v[index]);
    Solution(v, TargetSum, answer, index + 1, CurrentSum + v[index]);
}

int main()
{
    int n, TargetSum;
    cin >> n >> TargetSum;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> answer;
    Solution(v, TargetSum, answer, 0, 0);

    return 0;
}
