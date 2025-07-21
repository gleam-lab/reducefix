#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
#include <algorithm>
using namespace std;
using ll = long long;

const int inf = 1 << 30;
const ll INF = 1LL << 62;
using P = pair<ll, int>;

int N;
ll X;
vector<ll> A, P, B, Q;

// Function to check if it's possible to achieve processing capacity x with budget X
bool canAchieve(ll x) {
    ll totalCost = 0;
    for (int i = 0; i < N; ++i) {
        ll min_cost = INF;

        // Try all possible number of machine A (s)
        for (ll s = 0; s <= B[i]; ++s) {
            ll remaining = max(0LL, x - A[i] * s);
            ll t = (remaining + B[i] - 1) / B[i];
            if (t <= A[i]) {
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
                break;
            }
        }

        // Try all possible number of machine B (t)
        for (ll t = 0; t <= A[i]; ++t) {
            ll remaining = max(0LL, x - B[i] * t);
            ll s = (remaining + A[i] - 1) / A[i];
            if (s <= B[i]) {
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
                break;
            }
        }

        if (min_cost > X) return false;
        X -= min_cost;
    }
    return true;
}

int main() {
    cin >> N >> X;
    A.resize(N), P.resize(N), B.resize(N), Q.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Check if even the minimal required capacity (1) is achievable
    bool possible = false;
    for (int i = 0; i < N; ++i) {
        if (P[i] <= X || Q[i] <= X) {
            possible = true;
            break;
        }
    }
    if (!possible) {
        cout << 0 << endl;
        return 0;
    }

    // Binary search on processing capacity
    ll low = 0, high = 1e18;
    ll ans = 0;
    while (low <= high) {
        ll mid = (low + high) / 2;
        X = 10000000; // Reset X for each binary search iteration
        if (canAchieve(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}