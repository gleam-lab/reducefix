#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = n - 1; i >= (int)(0); i--)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)
#define ALL(a) (a).begin(), (a).end()
#define ALL_(a) (a), (a) + size(a)
#define IF_T if (Is_test)

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    unordered_set<ll> threats;

    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        --a, --b; // Convert to zero-based index

        // Define the 8 possible moves
        vector<pair<ll, ll>> moves = {
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto& [dx, dy] : moves) {
            ll nx = a + dx, ny = b + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                threats.insert(nx * N + ny);
            }
        }
    }

    ll total_squares = N * N;
    ll safe_squares = total_squares - threats.size();

    cout << safe_squares << endl;

    return 0;
}