#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr, int key)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            return mid + 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
    cout << "Enter the " << n << " elements in sorted Form\n";
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key Value you want to Search\n";
    cin >> key;
    cout << BinarySearch(arr, key) << "\n";
    return 0;
}
