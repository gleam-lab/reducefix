#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    set<pair<ll, ll>> unsafe;
    vector<pair<ll, ll>> pieces(M);

    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
        unsafe.insert({a, b});
    }

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (const auto &p : pieces) {
        ll a = p.first;
        ll b = p.second;
        for (int k = 0; k < 8; ++k) {
            ll new_a = a + dx[k];
            ll new_b = b + dy[k];
            if (new_a >= 1 && new_a <= N && new_b >= 1 && new_b <= N) {
                unsafe.insert({new_a, new_b});
            }
        }
    }

    ll total_squares = N * N;
    ll safe_squares = total_squares - unsafe.size();
    cout << safe_squares << endl;

    return 0;
}