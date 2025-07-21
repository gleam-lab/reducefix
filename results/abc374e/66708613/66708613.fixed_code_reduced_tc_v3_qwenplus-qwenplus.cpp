#include<iostream>
#include<string>
#include<vector>
#include<assert.h>
using namespace std;
using ll = long long;

const int inf = 1 << 30;
const ll INF = 1LL << 62;

// Function to check if we can achieve processing capacity 'x' within budget X
bool canAchieve(ll x, ll X, const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q) {
    int N = A.size();
    ll total_cost = 0;
    
    for (int i = 0; i < N; ++i) {
        ll min_cost = INF;

        // Try all possible numbers of machine A and compute required number of machine B
        for (ll s = 0; s <= B[i]; ++s) {
            ll needed_B = max(0LL, (x - A[i] * s + B[i] - 1) / B[i]);
            ll cost = s * P[i] + needed_B * Q[i];
            if (cost >= 0) min_cost = min(min_cost, cost);
        }

        // Try all possible numbers of machine B and compute required number of machine A
        for (ll t = 0; t <= A[i]; ++t) {
            ll needed_A = max(0LL, (x - B[i] * t + A[i] - 1) / A[i]);
            ll cost = t * Q[i] + needed_A * P[i];
            if (cost >= 0) min_cost = min(min_cost, cost);
        }

        if (min_cost == INF || X < min_cost) return false;
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

    // Check if there is any stage where neither machine can be bought at all
    bool impossible = false;
    for (int i = 0; i < N; ++i) {
        if (X < P[i] && X < Q[i]) {
            impossible = true;
            break;
        }
    }

    if (impossible) {
        cout << 0 << endl;
        return 0;
    }

    // Binary search on the maximum achievable processing capacity
    ll low = 0, high = 1LL << 60;
    ll result = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canAchieve(mid, X, A, P, B, Q)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;
}