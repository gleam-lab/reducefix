#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> p(n + 1);

        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        for (int i = 1; i <= n; i++) {
            p[i] = {a[i], b[i]};
        }

        // Sort by A_i descending, and then by B_i descending
        sort(p.begin(), p.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            if (x.first != y.first) return x.first > y.first;
            return x.second > y.second;
        });

        // Calculate the initial sum of B_i for the first k elements
        long long sum = 0;
        for (int i = 1; i <= k; i++) {
            sum += p[i].second;
        }

        // Calculate the initial answer
        long long ans = p[k].first * sum;

        // Use a min-heap to keep track of the largest B_i values
        priority_queue<long long, vector<long long>, greater<long long>> max_heap;

        for (int i = 1; i <= k; i++) {
            max_heap.push(p[i].second);
        }

        for (int i = k + 1; i <= n; i++) {
            // Remove the smallest B_i and add the next B_i
            sum = sum - max_heap.top();
            max_heap.pop();

            // Add the new B_i to the heap and the sum
            max_heap.push(p[i].second);
            sum += p[i].second;

            // Update the answer
            ans = min(ans, sum * p[i].first);
        }

        cout << ans << "\n";
    }

    return 0;
}