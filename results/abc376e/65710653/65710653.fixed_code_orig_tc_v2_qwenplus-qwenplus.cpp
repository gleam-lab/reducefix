#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; --i)
#define print_vec(v) for (auto &x : v) cout << x << " "; cout << endl;

struct Item {
    ll a, b;
};

bool compare(Item const& lhs, Item const& rhs) {
    return lhs.a < rhs.a;
}

// Main solution logic
void solve() {
    ll T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        vector<Item> items(N);
        for (ll i = 0; i < N; ++i) cin >> items[i].a;
        for (ll i = 0; i < N; ++i) cin >> items[i].b;

        sort(items.begin(), items.end(), compare);

        multiset<ll> top_b;
        ll sum_b = 0;
        // Initialize with first K elements
        for (ll i = 0; i < K; ++i) {
            sum_b += items[i].b;
            top_b.insert(items[i].b);
        }

        ll min_val = sum_b * items[K - 1].a;

        // Sliding window using multiset
        for (ll i = K; i < N; ++i) {
            if (*top_b.begin() < items[i].b) {
                sum_b -= *top_b.begin();
                sum_b += items[i].b;
                top_b.erase(top_b.begin());
                top_b.insert(items[i].b);
            }
            min_val = min(min_val, sum_b * items[i].a);
        }

        cout << min_val << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}