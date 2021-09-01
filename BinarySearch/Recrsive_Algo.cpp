/*
    Binary Search Algorithm
    Space Complex: O(1)
    Time Complex: O(log n)

    Merge Sort Algorithm
    Space Complex: O(1)
    Time Complex: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
//Implementing Binary search technique
int binarySearch(int arr[], int l, int r, int val){
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == val)
            return mid;
        if (arr[mid] > val)
            return binarySearch(arr, l, mid - 1, val);
        return binarySearch(arr, mid + 1, r, val);
    }
    return -1;
}

//Implementing merge sort technique
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
        cin >> x;
    display(arr, n);
    mergesort(arr, 0, n);
    display(arr, n);
    cout << "Enter the value to search" << endl;
    int val;
    cin >> val;
    cout << binarySearch(arr, 0, n, val) + 1 << endl;
    return 0;
}
