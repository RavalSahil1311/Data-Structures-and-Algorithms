#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of elements in Array\n";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the " << n << " elements\n";
    for (size_t i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (size_t i = 0; i < n - 1; i++)
    {
        bool swaped = true;
        for (size_t j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                swaped = false;
            }
        }
        if (swaped)
            break;
    }
    cout << "Sorted Array\n";
    for (size_t i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}