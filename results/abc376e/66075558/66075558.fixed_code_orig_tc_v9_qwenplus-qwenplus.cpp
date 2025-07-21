#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Item {
    ll a, b;
};

bool compare(const Item &x, const Item &y) {
    return x.a < y.a;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<Item> items(N);
        for (int i = 0; i < N; ++i)
            cin >> items[i].a;
        for (int i = 0; i < N; ++i)
            cin >> items[i].b;

        // Sort by A
        sort(items.begin(), items.end(), compare);

        priority_queue<ll> max_heap; // To maintain K smallest B's
        ll sum_b = 0;
        ll res = INF;

        for (int i = 0; i < N; ++i) {
            if (K > 0 && max_heap.size() >= K - 1) {
                // We have at least K-1 elements in heap, can form a set with current item
                res = min(res, items[i].a * (sum_b + items[i].b));
            }

            // Add current b to heap and manage size
            if (max_heap.size() < K - 1) {
                sum_b += items[i].b;
                max_heap.push(items[i].b);
            } else {
                // Maintain only the K-1 smallest B's
                if (!max_heap.empty() && items[i].b < max_heap.top()) {
                    sum_b -= max_heap.top();
                    max_heap.pop();
                    sum_b += items[i].b;
                    max_heap.push(items[i].b);
                }
            }
        }

        cout << res << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}