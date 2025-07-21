#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e9 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    set<pair<int, int>> positions;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        positions.insert({x, y});
        
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};
        for(int j = 0; j < 8; ++j) {
            int nx = x + dx[j], ny = y + dy[j];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                positions.insert({nx, ny});
            }
        }
    }

    cout << n * n - positions.size() << '\n';

    return 0;
}