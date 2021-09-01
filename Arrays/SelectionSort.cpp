#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void selectionSort(int arr[], int n)
{
    int i, j, minx;
    for (i = 0; i < n - 1; i++)
    {
        minx = i;
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[minx]){
                minx = j;
            }
        }
        swap(&arr[minx], &arr[i]);
    }
}
void display(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &x : arr)
    {
        cin >> x;
    }
    selectionSort(arr, n);
    display(arr, n);
    return 0;
}
