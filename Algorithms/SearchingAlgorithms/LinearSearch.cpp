#include <bits/stdc++.h>
using namespace std;

int LinearSearch(vector<int> arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            return i + 1;
        }
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
    cout << LinearSearch(arr, key) << "\n";
    return 0;
}
