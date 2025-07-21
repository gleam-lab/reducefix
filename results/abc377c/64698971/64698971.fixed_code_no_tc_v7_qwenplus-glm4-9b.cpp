#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrep(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define rrepi(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<pair<ll, ll>> dangers;
    vector<vector<int>> occupied(N, vector<int>(N, 0));

    for (ll i = 0; i < M; ++i) {
        ll x, y;
        cin >> x >> y;
        occupied[x - 1][y - 1] = 1;
        vector<pair<ll, ll>> moves = {
            {0, 0}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
        };

        for (auto& move : moves) {
            ll nx = x + move.first, ny = y + move.second;
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                dangers.emplace_back(nx, ny);
            }
        }
    }

    set<pair<ll, ll>> unique_dangers(dangers.begin(), dangers.end());

    ll total_squares = N * N;
    ll safe_squares = total_squares;

    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j < N; ++j) {
            if (!occupied[i][j]) { // If the square is empty
                auto it = unique_dangers.lower_bound({i, j});
                if (it != unique_dangers.begin()) {
                    --it;
                }
                auto upper_it = unique_dangers.upper_bound({i, j});
                if (upper_it == unique_dangers.end()) {
                    --upper_it;
                }

                if (it != unique_dangers.end() && upper_it != unique_dangers.begin()) {
                    ll left = it->second < j ? 0 : j - it->second;
                    ll right = upper_it->second > j ? 0 : upper_it->first - j;
                    ll bottom = it->first < i ? 0 : i - it->first;
                    ll top = upper_it->first > i ? 0 : upper_it->second - i;

                    safe_squares -= (left + right + bottom + top + 1);
                }
            }
        }
    }

    cout << safe_squares << endl;

    return 0;
}