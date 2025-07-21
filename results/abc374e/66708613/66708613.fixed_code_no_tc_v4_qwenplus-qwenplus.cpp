#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

// Function to check if processing capacity 'x' can be achieved within budget X
bool is_possible(ll x, ll X, const vector<ll>& A, const vector<ll>& P, 
                 const vector<ll>& B, const vector<ll>& Q, int N) {
    ll remaining_budget = X;

    for (int i = 0; i < N; ++i) {
        ll min_cost = INF;

        // Try all possible number of type-A machines (up to when cost would exceed INF)
        for (ll s = 0; ; ++s) {
            ll a_capacity = A[i] * s;
            if (a_capacity >= x) {
                min_cost = min(min_cost, s * P[i]);
                break;
            }
            ll needed_b_capacity = max(0LL, x - a_capacity);
            ll t = (needed_b_capacity + B[i] - 1) / B[i]; // ceil division
            if (t > INF) break; // prevent overflow
            min_cost = min(min_cost, s * P[i] + t * Q[i]);
            if (s * P[i] > INF) break; // prevent infinite loop due to overflow
        }

        // Try all possible number of type-B machines (up to when cost would exceed INF)
        for (ll t = 0; ; ++t) {
            ll b_capacity = B[i] * t;
            if (b_capacity >= x) {
                min_cost = min(min_cost, t * Q[i]);
                break;
            }
            ll needed_a_capacity = max(0LL, x - b_capacity);
            ll s = (needed_a_capacity + A[i] - 1) / A[i]; // ceil division
            if (s > INF) break; // prevent overflow
            min_cost = min(min_cost, t * Q[i] + s * P[i]);
            if (t * Q[i] > INF) break; // prevent infinite loop due to overflow
        }

        if (min_cost > remaining_budget) {
            return false;
        }
        remaining_budget -= min_cost;
    }

    return true;
}

int main() {
    int N;
    ll X;
    cin >> N >> X;
    
    vector<ll> A(N), P(N), B(N), Q(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Binary search on the processing capacity
    ll low = 0;
    ll high = 1LL << 60;

    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (is_possible(mid, X, A, P, B, Q, N)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << endl;
    return 0;
}