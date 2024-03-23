#include <bits/stdc++.h>
using namespace std;

int JumpSearch(vector<int> arr, int key)
{
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < key)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
        {
            return -1;
        }
    }

    while (arr[prev] < key)
    {
        prev++;
        if (prev == min(step, n))
        {
            return -1;
        }
    }

    if (arr[prev] == key)
    {
        return prev + 1;
    }
    return -1;
}

int main()
{
    int n, key;
    cout << "Enter the number of elements in Array\n";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the " << n << " elements\n";
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key Value you want to Search\n";
    cin >> key;
    cout << JumpSearch(arr, key) << "\n";
    return 0;
}
