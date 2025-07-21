#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int inf = 1 << 30;
const ll INF = 1LL << 62;

// Function to check if we can achieve processing capacity 'x' within budget 'X'
bool canAchieve(ll x, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    int N = A.size();
    ll total_cost = 0;

    for (int i = 0; i < N; ++i) {
        ll min_cost = INF;

        // Try all possible numbers of machine A (s), bounded by needed amount or max available
        for (ll s = 0; s <= min(B[i], x / A[i]) + 1 && s <= B[i]; ++s) {
            ll remaining = max(0LL, x - A[i] * s);
            ll t = (remaining + B[i] - 1) / B[i]; // ceiling division
            if (t <= A[i]) {
                min_cost = min(min_cost, s * P[i] + t * Q[i]);
            }
        }

        // Try all possible numbers of machine B (t), bounded similarly
        for (ll t = 0; t <= min(A[i], x / B[i]) + 1 && t <= A[i]; ++t) {
            ll remaining = max(0LL, x - B[i] * t);
            ll s = (remaining + A[i] - 1) / A[i]; // ceiling division
            if (s <= B[i]) {
                min_cost = min(min_cost, t * Q[i] + s * P[i]);
            }
        }

        if (min_cost > X) {
            return false; // Cannot afford this stage
        }
        X -= min_cost;
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

    // Check if even the minimum required purchase is possible at any stage
    for (int i = 0; i < N; ++i) {
        if (X < P[i] && X < Q[i]) {
            cout << 0 << endl;
            return 0;
        }
    }

    // Binary search on maximum processing capacity
    ll lb = 0, ub = 1LL << 60;

    while (lb < ub) {
        ll mid = (ub + lb + 1) / 2; // Use +1 to avoid infinite loop in case of integer overflow
        if (canAchieve(mid, X, A, P, B, Q)) {
            lb = mid;
        } else {
            ub = mid - 1;
        }
    }

    cout << lb << endl;

    return 0;
}