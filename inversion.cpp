#include <bits/stdc++.h>
using namespace std;
int n;
long long MOD = 1000000007;
int A[1000000];
long long _mergeSort(int A[], int temp[], int left, int right);
long long merge(int A[], int temp[], int left, int mid, int right);

long long mergeSort(int A[], int Asize)
{
    int temp[Asize];
    return _mergeSort(A, temp, 0, Asize - 1);
}

long long _mergeSort(int A[], int temp[], int left, int right)
{
    int mid;
    long long inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        inv_count += _mergeSort(A, temp, left, mid);
        inv_count += _mergeSort(A, temp, mid + 1, right);

        inv_count += merge(A, temp, left, mid + 1, right);
    }
    return inv_count;
}

long long merge(int A[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    long long inv_count = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (A[i] <= A[j])
        {
            temp[k++] = A[i++];
        }
        else
        {
            temp[k++] = A[j++];
            inv_count += (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = A[i++];

    while (j <= right)
        temp[k++] = A[j++];

    for (i = left; i <= right; i++)
        A[i] = temp[i];

    return inv_count;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << mergeSort(A, n) % MOD;
}
