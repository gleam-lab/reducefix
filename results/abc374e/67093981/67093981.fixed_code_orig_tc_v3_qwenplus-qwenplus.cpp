#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

struct Machine {
    int a, p, b, q;
};

int main() {
    int N;
    ll X;
    cin >> N >> X;

    vector<vector<ll>> dp(N);
    vector<Machine> machines(N);

    for (int i = 0; i < N; ++i) {
        int a, p, b, q;
        cin >> a >> p >> b >> q;

        if ((ll)a * q < (ll)b * p) {
            swap(a, b);
            swap(p, q);
        }
        machines[i] = {a, p, b, q};

        int period = a * b;
        dp[i].resize(period + 1);

        dp[i][0] = 0;
        for (int j = 1; j <= period; ++j) {
            dp[i][j] = LLONG_MAX;
            if (j >= a) {
                dp[i][j] = min(dp[i][j], dp[i][j - a] + p);
            }
            if (j >= b) {
                dp[i][j] = min(dp[i][j], dp[i][j - b] + q);
            }
        }

        // Extend the DP using periodicity property
        ll base_cost = dp[i][period];
        for (int j = 1; j <= period; ++j) {
            dp[i][j] += (base_cost * (j / period));
        }
    }

    auto is_possible = [&](ll target) -> bool {
        ll total_cost = 0;
        for (int i = 0; i < N; ++i) {
            ll d = target / (machines[i].a * machines[i].b);
            ll rem = target % (machines[i].a * machines[i].b);
            ll cost = d * machines[i].p * machines[i].b + dp[i][rem];
            total_cost += cost;
            if (total_cost > X)
                return false;
        }
        return true;
    };

    ll low = 0;
    ll high = 2e18;
    ll answer = 0;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (is_possible(mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << endl;
}