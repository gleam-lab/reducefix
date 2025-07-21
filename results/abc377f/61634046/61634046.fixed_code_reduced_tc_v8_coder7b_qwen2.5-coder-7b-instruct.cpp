#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e9 + 10;

long long n, m;
vector<pair<int, int>> pieces;

bool valid(int x, int y) {
    for(auto& [px, py] : pieces) {
        if(px == x || py == y || px + py == x + y || px - py == x - y) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    pieces.resize(m);
    for(auto& [x, y] : pieces) cin >> x >> y;

    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(valid(i, j)) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}