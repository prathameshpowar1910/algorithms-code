#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int r)
{

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[i + l];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[i + mid + 1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {

        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int size = 8;
    int arr[size] = {3, 5, 4, 2, 6, 7, 1, 8};

    int l = 0;
    int r = size - 1;
    mergesort(arr, l, r);

    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
    return 0;
}
