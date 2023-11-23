#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> ls;
    int n, tmp;
    cin >> n;
    while (n--)
    {
        cin >> tmp;
        ls.push_back(tmp);
    }
    sort(ls.begin(), ls.end());
    for (int i : ls)
    {
        cout << i << " ";
    }
}