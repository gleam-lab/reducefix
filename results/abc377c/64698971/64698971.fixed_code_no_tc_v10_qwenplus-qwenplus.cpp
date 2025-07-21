#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll N;
    int M;
    cin >> N >> M;

    // Use a hash set to store attacked positions or occupied positions
    unordered_set<string> blocked;

    // Helper function to convert (a, b) to string for storing in set
    auto key = [](ll x, ll y) {
        return to_string(x) + "," + to_string(y);
    };

    vector<pair<ll, ll>> dir = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < M; ++i) {
        ll a, b;
        cin >> a >> b;
        // Block the position itself
        blocked.insert(key(a, b));
        // Block all positions that can be attacked from (a, b)
        for (auto [dx, dy] : dir) {
            ll na = a + dx;
            ll nb = b + dy;
            if (1 <= na && na <= N && 1 <= nb && nb <= N) {
                blocked.insert(key(na, nb));
            }
        }
    }

    // Total number of cells is N*N
    // Subtract the number of blocked/occupied cells
    cout << (N * N) - (ll)blocked.size() << endl;

    return 0;
}