#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, M;
    cin >> N >> M;

    vector<ll> A, B, C, D;
    unordered_set<ll> occupied_lines[4];

    for (ll i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        A.push_back(a + b);
        B.push_back(a - b);
        C.push_back(a);
        D.push_back(b);
        occupied_lines[0].insert(a + b);
        occupied_lines[1].insert(a - b);
        occupied_lines[2].insert(a);
        occupied_lines[3].insert(b);
    }

    ll valid_positions = 0;

    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= N; j++) {
            bool is_valid = true;
            for (ll k = 0; k < 4; k++) {
                if (occupied_lines[k].count(i + (k == 1 ? -j : (k == 2 ? 0 : (k == 3 ? 0 : j)))) > 0) {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid) {
                valid_positions++;
            }
        }
    }

    cout << valid_positions << endl;

    return 0;
}