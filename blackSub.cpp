#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
    }
    // clear the stack to be re-used
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
    }
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
}
// rectangle;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> rec(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> rec[i][j];
        }
    }
    // built height
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rec[i][j] == 1)
            {
                rec[i][j] = rec[i - 1][j] + 1;
            }
        }
    }
    int maxarea = -999;
    for (auto i : rec)
    {
        maxarea = max(largestRectangleArea(i), maxarea);
    }
    cout << maxarea;
}