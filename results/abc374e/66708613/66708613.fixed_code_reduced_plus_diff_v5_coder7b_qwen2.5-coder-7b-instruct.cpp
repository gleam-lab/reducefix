#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cassert>
#include <random>
#include <set>
#include <map>
#include <cassert>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <algorithm>
using namespace std;
using ll = long long;
const int inf = 1 << 30;
const ll INF = 1LL << 62;
using P = pair<ll, int>;
using PP = pair<int, P>;
const ll MOD = 998244353;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool can_meet_capacity(const vector<ll>& A, const vector<ll>& P, const vector<ll>& B, const vector<ll>& Q, ll X, ll target) {
    for (int i = 0; i < A.size(); ++i) {
        ll remaining_budget = X;
        bool found = false;

        // Try using machine type B first
        for (ll s = 0; s <= B[i]; ++s) {
            ll t = (max(0LL, target - A[i] * s) + B[i] - 1) / B[i];
            ll cost = s * P[i] + t * Q[i];
            if (cost <= remaining_budget) {
                remaining_budget -= cost;
                found = true;
                break;
            }
        }

        // If not possible with B, try machine type A
        if (!found) {
            for (ll t = 0; t <= A[i]; ++t) {
                ll s = (max(0LL, target - B[i] * t) + A[i] - 1) / A[i];
                ll cost = t * Q[i] + s * P[i];
                if (cost <= remaining_budget) {
                    remaining_budget -= cost;
                    found = true;
                    break;
                }
            }
        }

        // If still not possible, return false
        if (!found) {
            return false;
        }
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

    ll ub = X, lb = 0; // Initialize upper bound as X and lower bound as 0
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if (can_meet_capacity(A, P, B, Q, X, mid)) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << lb << endl; // Output the minimum processing capacity that can be achieved within budget X.
}