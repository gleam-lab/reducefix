#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;

const int inf = 1 << 30;
const ll INF = 1LL << 62;

int N;
ll X;
vector<ll> A, P, B, Q;

// Check if it's possible to achieve processing capacity x with budget X
bool can_achieve(ll x) {
    ll total_cost = 0;
    
    for (int i = 0; i < N; ++i) {
        ll min_cost = INF;
        
        // Try all possible number of type A machines within reasonable bounds
        for (ll s = 0; s <= B[i] && A[i] * s >= 0; ++s) {
            ll remaining = max(0LL, x - A[i] * s);
            ll t = (remaining + B[i] - 1) / B[i]; // ceil division
            if (t > B[i]) continue; // cannot use more than available
            min_cost = min(min_cost, s * P[i] + t * Q[i]);
        }
        
        // Try all possible number of type B machines within reasonable bounds
        for (ll t = 0; t <= A[i] && B[i] * t >= 0; ++t) {
            ll remaining = max(0LL, x - B[i] * t);
            ll s = (remaining + A[i] - 1) / A[i]; // ceil division
            if (s > A[i]) continue; // cannot use more than available
            min_cost = min(min_cost, t * Q[i] + s * P[i]);
        }

        if (min_cost == INF) return false; // Cannot achieve this processing capability
        total_cost += min_cost;
        
        if (total_cost > X) return false; // Exceeds budget
    }
    
    return total_cost <= X;
}

int main() {
    cin >> N >> X;
    A.resize(N), P.resize(N), B.resize(N), Q.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Early check: If for any stage, we can't buy at least one machine
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        if (X < P[i] && X < Q[i]) {
            possible = false;
            break;
        }
    }
    if (!possible) {
        cout << 0 << endl;
        return 0;
    }

    // Binary search on the answer
    ll low = 0, high = 1e18;
    ll result = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (can_achieve(mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}