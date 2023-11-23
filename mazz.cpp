#include <bits/stdc++.h>
using namespace std;
int m, n, r, c;
typedef struct coordinate
{
    int x, y;
    int dist; // distance
} cdn;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool stopFind(int x, int y)
{
    return (x == 0 || x == m - 1 || y == 0 || y == n - 1);
}

int findMinEscape(vector<vector<int>> mazz)
{
    bool visited[m][n];
    memset(visited, false, sizeof(visited));
    visited[r][c] = true;
    queue<cdn> q;
    cdn s = {r, c, 0};
    q.push(s);

    while (!q.empty())
    {
        cdn curr = q.front();
        int x = curr.x;
        int y = curr.y;
        if (stopFind(x, y))
        {
            return curr.dist + 1;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = curr.x + dx[i];
            int col = curr.y + dy[i];

            if (mazz[row][col] != 1 && !visited[row][col])
            {
                visited[row][col] = true;
                cdn Adjcell = {row, col, curr.dist + 1};
                q.push(Adjcell);
            }
        }
    }
    return -1;
}
int main()
{

    cin >> m >> n >> r >> c;
    r -= 1;
    c -= 1;
    vector<vector<int>> mazz(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mazz[i][j];
        }
    }

    cout << findMinEscape(mazz);
}