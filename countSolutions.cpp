#include <bits/stdc++.h>
using namespace std;
int kq = 0;
void countSolutions(int k, vector<int> heso, int M, int n)
{
    if (M <= 0)
    {
        return;
    }
    for (int i = 1; i * heso[k - 1] <= M - n + k; i++) // M - i*heso[k-1] >= n - k
    {
        if (k == n && M % heso[k - 1] == 0)
        {
            kq++;
            return;
        }
        else
        {
            countSolutions(k + 1, heso, M - heso[k - 1] * i, n);
        }
    }
}
int main()
{
    int n, M;
    cin >> n >> M;
    vector<int> heso(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heso[i];
    }
    countSolutions(1, heso, M, n);
    cout << kq;
}