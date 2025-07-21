#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define per(i, a, b) for (ll i = a; i >= b; --i)

struct Item {
    ll a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;

    while (T--) {
        ll N, K;
        cin >> N >> K;

        vector<Item> items(N);
        for (ll i = 0; i < N; ++i) {
            cin >> items[i].a;
        }
        for (ll i = 0; i < N; ++i) {
            cin >> items[i].b;
        }

        // Sort by A in ascending order
        sort(items.begin(), items.end(), [](const Item& x, const Item& y) {
            return x.a < y.a;
        });

        multiset<ll> b_set;
        ll sum_b = 0;

        // Initialize with the first K elements
        for (ll i = 0; i < K; ++i) {
            b_set.insert(items[i].b);
            sum_b += items[i].b;
        }

        ll min_result = sum_b * items[K - 1].a;

        // Sliding window approach
        for (ll i = K; i < N; ++i) {
            // Remove the largest b value in the current set
            b_set.erase(prev(b_set.end()));
            // Add the new b value
            b_set.insert(items[i].b);
            sum_b = accumulate(b_set.begin(), b_set.end(), 0LL);
            min_result = min(min_result, sum_b * items[i].a);
        }

        cout << min_result << endl;
    }

    return 0;
}