#include <bits/stdc++.h>
using namespace std;
string keyborad[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int searchIndex(char c)
{
    for (int i = 0; i < 8; i++)
    {
        if (keyborad[i].find(c) != string::npos)
        {
            return keyborad[i].find(c);
        }
    }
    return 0;
}
int countPress(string s)
{
    int result = 0;
    int slen = s.length();
    for (int i = 0; i < slen; i++)
    {
        result += searchIndex(s[i]) + 1;
    }
    return result;
}

int main()
{
    cout << countPress("???");
}