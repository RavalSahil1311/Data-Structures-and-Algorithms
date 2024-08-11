#include <bits/stdc++.h>
using namespace std;

void Heapify(vector<int> &arr, int size, int index)
{
    int left = 2 * index, right = 2 * index + 1;
    int largest = index;
    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (index != largest)
    {
        swap(arr[largest], arr[index]);
        Heapify(arr, size, largest);
    }
}

void HeapSort(vector<int> &arr, int n)
{
    for (int i = (n / 2) + 1; i > 0; i--)
    {
        Heapify(arr, n, i);
    }
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        Heapify(arr, size, 1);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of elements in Array\n";
    cin >> n;
    vector<int> arr(n + 1);
    cout << "Enter the " << n << " elements\n";
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    HeapSort(arr, arr.size() - 1);
    for (int i = 1; i < n + 1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
