#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
// unsigned long long computeplus(unsigned long long m, unsigned long long n){
//     int i = 1;
//     unsigned long long result = 0;
//     while (i != n){
//         result
//     }
// }

unsigned long long computeEXPMOD(unsigned long long a, unsigned long long b)
{
    if (b == 0)
        return 1;

    unsigned long long tmp = computeEXPMOD(a, b / 2);
    tmp = (tmp * tmp) % P;
    if (b % 2 != 0)
    {
        tmp = (tmp * (a % P)) % P;
    }

    return tmp;
}
int main()
{
    unsigned long long a, b;
    cin >> a >> b;
    cout << computeEXPMOD(a, b) << "\n";
}