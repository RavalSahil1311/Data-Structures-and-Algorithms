#include <bits/stdc++.h>
using namespace std;

int partition(int start, int end, vector<int> &arr)
{
    int pivot = arr[start];
    int pivotIndex = start, count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivotIndex)
        {
            j--;
        }
    }
    if (i < pivotIndex && j > pivotIndex)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    return pivotIndex;
}

void Quicksort(int start, int end, vector<int> &arr)
{
    if (start >= end)
    {
        return;
    }
    int p = partition(start, end, arr);
    Quicksort(start, p - 1, arr);
    Quicksort(p + 1, end, arr);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of elements in Array\n";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the " << n << " elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Quicksort(0, arr.size() - 1, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
