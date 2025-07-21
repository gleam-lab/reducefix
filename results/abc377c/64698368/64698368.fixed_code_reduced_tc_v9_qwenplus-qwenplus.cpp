#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

using ll = long long;

int N, M;
set<pair<ll, ll>> attacked;

const array<array<int, 2>, 9> dirs = {{
    {0, 0},
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
}};

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        for (auto& d : dirs) {
            ll na = a + d[0];
            ll nb = b + d[1];
            if (na >= 0 && na < N && nb >= 0 && nb < N) {
                attacked.insert({na, nb});
            }
        }
    }

    cout << (1LL * N * N - (ll)attacked.size()) << endl;
}