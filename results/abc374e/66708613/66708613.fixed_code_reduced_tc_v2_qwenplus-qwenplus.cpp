#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cassert>
#include <random>
#include <set>
#include <map>
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

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    auto f = [&](ll x) {
        // Check if processing capacity x can be achieved with budget X
        ll remaining = X;
        for (int i = 0; i < N; ++i) {
            ll min_cost = INF;

            // Try different numbers of machine A used
            // s = number of A machines used, t = number of B machines used
            // A[i] * s + B[i] * t >= x
            // Try s from 0 to min(max_s, A[i]) where max_s = ceil(x / A[i])
            ll max_a_try = min(A[i], (x + B[i] - 1) / B[i]);
            for (ll s = 0; s <= max_a_try && s * P[i] <= X; ++s) {
                ll required_b = (max(0LL, x - A[i] * s) + B[i] - 1) / B[i];
                if (required_b <= Q[i] * X) {
                    min_cost = min(min_cost, s * P[i] + required_b * Q[i]);
                }
            }

            // Try different numbers of machine B used
            ll max_b_try = min(B[i], (x + A[i] - 1) / A[i]);
            for (ll t = 0; t <= max_b_try && t * Q[i] <= X; ++t) {
                ll required_a = (max(0LL, x - B[i] * t) + A[i] - 1) / A[i];
                if (required_a * P[i] <= X) {
                    min_cost = min(min_cost, t * Q[i] + required_a * P[i]);
                }
            }

            if (min_cost > X || min_cost == INF) {
                return false;
            }
            remaining -= min_cost;
            if (remaining < 0) {
                return false;
            }
        }
        return true;
    };

    // Binary search for maximum achievable processing capacity
    ll low = 0, high = 1;
    while (f(high)) {
        low = high;
        high *= 2;
    }

    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (f(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << endl;
}