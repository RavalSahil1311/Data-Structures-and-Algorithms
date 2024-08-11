#include <bits/stdc++.h>
using namespace std;

int TernarySearch(vector<int> arr, int key)
{
    int low = 0, high = arr.size();
    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (arr[mid1] == key)
        {
            return mid1 + 1;
        }
        if (arr[mid2] == key)
        {
            return mid2 + 1;
        }
        if (key < arr[mid1])
        {
            high = mid1 - 1;
        }
        else if (key > arr[mid2])
        {
            low = mid2 + 1;
        }
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
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
    cout << TernarySearch(arr, key) << "\n";
    return 0;
}