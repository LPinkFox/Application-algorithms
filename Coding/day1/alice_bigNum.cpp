#include <bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
    int alen = a.length();
    int blen = b.length();
    string result;
    int flag = 0;

    if (alen > blen)
    {
        b.insert(0, alen - blen, '0');
    }
    else
    {
        a.insert(0, blen - alen, '0');
    }

    for (int i = max(alen, blen) - 1; i >= 0; i--)
    {
        int x = b[i] - 48;
        int y = a[i] - 48;

        if (x + y + flag >= 10)
        {
            result = to_string((x + y + flag) % 10) + result;
            flag = 1;
        }
        else
        {
            result = to_string(x + y + flag) + result;
            flag = 0;
        }
    }
    if (flag == 1)
    {
        result = to_string(flag) + result;
    }
    return result;
}
int main()
{
    cout << add("123", "1234789789789");
    return 0;
}