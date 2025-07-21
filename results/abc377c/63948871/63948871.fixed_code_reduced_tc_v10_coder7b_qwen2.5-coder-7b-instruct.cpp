#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    ll M;
    cin >> N >> M;

    set<pair<ll, ll>> pieces;
    for (ll i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        pieces.insert({a, b});
    }

    ll count = 0;
    for (ll i = 1; i <= N; ++i) {
        for (ll j = 1; j <= N; ++j) {
            bool is_safe = true;
            for (const auto& [x, y] : pieces) {
                if ((abs(i - x) == 2 && abs(j - y) == 1) ||
                    (abs(i - x) == 1 && abs(j - y) == 2)) {
                    is_safe = false;
                    break;
                }
            }
            if (is_safe) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}