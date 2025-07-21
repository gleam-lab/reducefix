#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n, m, k, sum, cnt, a[N];
int distance(int x, int y)
{
    return abs(x - y);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int i, j, x, y, z, t;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (j = 0; j < m; j++)
    {
        cin >> x >> y;
        vector<int> dist;
        for (i = 0; i < n; i++)
            dist.push_back(distance(a[i], x));
        sort(dist.begin(), dist.end());
        cout << dist[y - 1] << endl;
    }
    return 0;
}