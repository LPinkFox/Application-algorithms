#include <iostream>
using namespace std;
int compute(int check)
{
    int result = 0;
    while (check)
    {
        int surplus = check % 10;
        result += surplus * surplus;
        check = check / 10;
    }
    return result;
}
bool isHappy(int n)
{
    int check = n;
    while (true)
    {
        check = compute(check);
        if (check == 1)
            break;
        if (check == n)
            break;
    }
    return check == 1;
}
int main()
{
    // Write C++ code here
    cout << isHappy(19);

    return 0;
}