#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    int arr[100];
    int size;
    MaxHeap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < value)
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void Remove()
    {
        if (size == 0)
        {
            cout << "There is nothing to Delete\n";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void Print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

void Heapify(int arr[], int size, int index)
{
    int largest = index;
    int left = index * 2;
    int right = index * 2 + 1;

    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        Heapify(arr, size, largest);
    }
}

int main()
{
    MaxHeap H;
    while (true)
    {
        cout << "(1).Press 1 for adding Element in MaxHeap\n";
        cout << "(2).Press 2 for deleting Element from MaxHeap\n";
        cout << "(3).Press 3 for printing all Element of MaxHeap\n";
        cout << "(4).Press 4 for exiting the program\n";
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the Element to add in heap\n";
            int x;
            cin >> x;
            H.insert(x);
            break;

        case 2:
            H.Remove();
            break;

        case 3:
            H.Print();
            break;
        }
        if (n == 4)
        {
            break;
        }
    }
}