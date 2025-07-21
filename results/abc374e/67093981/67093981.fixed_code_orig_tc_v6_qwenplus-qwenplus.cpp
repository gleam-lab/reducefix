#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Item {
    int a, p, b, q;
};

int N;
ll X;
vector<Item> items;
vector<vector<ll>> dp;

// Calculate minimal cost to produce n units using i-th item
ll cost(int i, ll n) {
    Item &it = items[i];
    ll full_cycles = n / (1LL * it.a * it.b);
    ll remainder = n % (1LL * it.a * it.b);
    return full_cycles * (1LL * it.p * it.b + 1LL * it.q * it.a) + dp[i][remainder];
}

// Check if we can produce 'n' total units within budget X
bool feasible(ll n) {
    ll total_cost = 0;
    for (int i = 0; i < N; ++i) {
        total_cost += cost(i, n);
        if (total_cost > X) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;

    items.resize(N);
    dp.resize(N);

    for (int i = 0; i < N; ++i) {
        Item &it = items[i];
        cin >> it.a >> it.p >> it.b >> it.q;

        // Ensure a*p <= b*q
        if (1LL * it.a * it.q > 1LL * it.b * it.p) {
            swap(it.a, it.b);
            swap(it.p, it.q);
        }

        // Precompute min cost for 0..a*b units
        dp[i].assign(1 + it.a * it.b, 0);
        for (int j = 1; j <= it.a * it.b; ++j) {
            dp[i][j] = 1LL << 60;
            if (j >= it.a) dp[i][j] = min(dp[i][j], dp[i][j - it.a] + it.p);
            if (j >= it.b) dp[i][j] = min(dp[i][j], dp[i][j - it.b] + it.q);
        }
    }

    // Binary search for max feasible number of units
    ll low = 0, high = 2e18;
    while (low < high) {
        ll mid = (low + high + 1) / 2;
        if (feasible(mid)) low = mid;
        else high = mid - 1;
    }

    cout << low << endl;

    return 0;
}