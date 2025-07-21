#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int N, int M, vector<pair<int, int>>& pos, int i, int j) {
    for(auto [x, y]: pos) {
        if(i == x || j == y || i + j == x + y || i - j == x - y) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N, M; cin >> N >> M;
    vector<pair<int, int>> pos(M);
    for(int i = 0; i < M; ++i) {
        int x, y; cin >> x >> y;
        --x, --y; // Adjusting for 0-based indexing
        pos[i] = {x, y};
    }

    int ans = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(check(N, M, pos, i, j)) ++ans;
        }
    }

    cout << ans << '\n';

    return 0;
}