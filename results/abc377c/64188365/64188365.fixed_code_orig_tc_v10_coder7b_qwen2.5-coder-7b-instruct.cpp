#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    long long n, m, a, b;
    cin >> n >> m;
    int ans = 0;
    set<pair<long long, long long>> c;
    rep(i, m) {
        cin >> a >> b;
        a--, b--;
        c.emplace(a, b);
        vector<pair<int, int>> directions = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
        for(auto [dx, dy] : directions) {
            int nx = a + dx, ny = b + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < n) {
                c.emplace(nx, ny);
            }
        }
    }
    cout << n * n - c.size() << endl;
}