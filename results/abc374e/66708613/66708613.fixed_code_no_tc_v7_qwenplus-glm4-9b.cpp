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

bool can_buy(ll budget, const vector<ll>& A, const vector<int>& P, const vector<ll>& B, const vector<ll>& Q) {
    for (int i = 0; i < A.size(); i++) {
        if (budget < P[i] && budget < Q[i]) {
            return false;
        }
    }
    return true;
}

ll min_cost_to_reach_capacity(ll budget, const vector<ll>& A, const vector<int>& P, const vector<ll>& B, const vector<ll>& Q) {
    ll res = budget;
    for (int i = 0; i < A.size(); i++) {
        ll min_cost = INF;
        for (ll s = 0; s <= B[i]; s++) {
            ll t = (max(0LL, budget - A[i] * s) + B[i] - 1) / B[i];
            min_cost = min(min_cost, s * P[i] + t * Q[i]);
        }

        for (ll t = 0; t <= A[i]; t++) {
            ll s = (max(0LL, budget - B[i] * t) + A[i] - 1) / A[i];
            min_cost = min(min_cost, t * Q[i] + s * P[i]);
        }
        res -= min_cost;
    }
    return res >= 0 ? res : -1; // If res < 0, it means it's not possible to achieve the required capacity within the budget
}

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    if (!can_buy(X, A, P, B, Q)) {
        cout << 0 << endl;
        return 0;
    }

    ll lb = 0, ub = 1LL << 60;
    while (ub - lb > 1) {
        ll mid = (ub + lb) / 2;
        if (min_cost_to_reach_capacity(X, A, P, B, Q) >= 0 && min_cost_to_reach_capacity(mid, A, P, B, Q) >= 0) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    cout << ub << endl; // Output the minimum processing capacity that can be achieved within budget X.
    return 0;
}