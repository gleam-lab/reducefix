#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> forbidden;
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        forbidden.emplace(a, b);
        // Check all 8 possible knight moves
        for (int di = -2; di <= 2; di++) {
            for (int dj = -2; dj <= 2; dj++) {
                if (abs(di) + abs(dj) == 3) {
                    ll ni = a - 1 + di;
                    ll nj = b - 1 + dj;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                        forbidden.emplace(ni, nj);
                    }
                }
            }
        }
    }
    cout << N * N - forbidden.size() << endl;
}