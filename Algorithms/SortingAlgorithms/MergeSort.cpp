#include <bits/stdc++.h>
using namespace std;

void merge(int start, int mid, int end, vector<int> &v)
{
    int ArrayOneSize = mid - start + 1, ArrayTwoSize = end - mid;
    vector<int> ArrayOne(ArrayOneSize), ArrayTwo(ArrayTwoSize);
    for (int i = 0; i < ArrayOne.size(); i++)
    {
        ArrayOne[i] = v[i + start];
    }
    for (int i = 0; i < ArrayTwo.size(); i++)
    {
        ArrayTwo[i] = v[i + mid + 1];
    }
    int IndexArrayOne = 0, IndexArrayTwo = 0, IndexMergeArray = start;
    while (IndexArrayOne < ArrayOneSize && IndexArrayTwo < ArrayTwoSize)
    {
        if (ArrayOne[IndexArrayOne] <= ArrayTwo[IndexArrayTwo])
        {
            v[IndexMergeArray] = ArrayOne[IndexArrayOne];
            IndexArrayOne++;
        }
        else
        {
            v[IndexMergeArray] = ArrayTwo[IndexArrayTwo];
            IndexArrayTwo++;
        }
        IndexMergeArray++;
    }
    while (IndexArrayOne < ArrayOneSize)
    {
        v[IndexMergeArray] = ArrayOne[IndexArrayOne];
        IndexArrayOne++;
        IndexMergeArray++;
    }
    while (IndexArrayTwo < ArrayTwoSize)
    {
        v[IndexMergeArray] = ArrayTwo[IndexArrayTwo];
        IndexArrayTwo++;
        IndexMergeArray++;
    }
}

void MergeSort(int start, int end, vector<int> &v)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    MergeSort(start, mid, v);
    MergeSort(mid + 1, end, v);
    merge(start, mid, end, v);
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
    MergeSort(0, arr.size() - 1, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
