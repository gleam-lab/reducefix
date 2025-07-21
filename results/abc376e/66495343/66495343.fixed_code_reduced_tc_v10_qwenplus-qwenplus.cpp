#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int INF = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<PII> items(n);
        for (int i = 0; i < n; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> items[i].second;
        }

        // Sort by A_i ascending
        sort(items.begin(), items.end());

        int res = INF;
        int sum_b = 0;
        priority_queue<int> max_heap; // to store B_i values we might remove

        for (int i = 0; i < n; ++i) {
            sum_b += items[i].second;
            max_heap.push(items[i].second);

            if (i >= k - 1) {
                // We have selected i+1 elements, maintain only k-1 smallest B_i in heap
                while (max_heap.size() > k - 1) {
                    sum_b -= max_heap.top();
                    max_heap.pop();
                }
                res = min(res, items[i].first * sum_b);
            }
        }

        cout << res << '\n';
    }

    return 0;
}