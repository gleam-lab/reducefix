#include <iostream>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;
using ll = long long;

const int inf = 1 << 30;
const ll INF = 1LL << 62;
using P = pair<ll, int>;
using PP = pair<int, P>;

int main() {
    int N;
    ll X;
    cin >> N >> X;
    vector<ll> A(N), P(N), B(N), Q(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> P[i] >> B[i] >> Q[i];
    }

    // Function to check if we can achieve processing capacity x with budget X
    auto is_possible = [&](ll x) {
        ll total_cost = 0;

        for (int i = 0; i < N; ++i) {
            ll min_cost = INF;

            // Try all possible numbers of machine A used up to this step
            for (ll a = 0; a * A[i] <= x && a <= B[i]; ++a) {
                ll remaining = max(0LL, x - a * A[i]);
                ll b_needed = (remaining + B[i] - 1) / B[i];
                if (b_needed <= A[i]) {
                    ll cost = a * P[i] + b_needed * Q[i];
                    min_cost = min(min_cost, cost);
                }
            }

            // Try all possible numbers of machine B used up to this step
            for (ll b = 0; b * B[i] <= x && b <= A[i]; ++b) {
                ll remaining = max(0LL, x - b * B[i]);
                ll a_needed = (remaining + A[i] - 1) / A[i];
                if (a_needed <= B[i]) {
                    ll cost = b * Q[i] + a_needed * P[i];
                    min_cost = min(min_cost, cost);
                }
            }

            if (min_cost == INF || total_cost > X) {
                return false; // Not possible to achieve this processing capacity
            }

            total_cost += min_cost;
        }

        return total_cost <= X;
    };

    // Binary search for the maximum achievable processing capacity
    ll low = 0, high = 1LL << 60;
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (is_possible(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << endl;
    return 0;
}