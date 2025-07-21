#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> items(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> items[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> items[i].second;
        }

        // Sort items by A_i (ascending)
        sort(items.begin(), items.end());

        // Min-heap to keep track of the K largest B_i values among the first i elements
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum_b = 0;
        long long result = 1e18; // Initialize with a large number

        // Take first K elements based on smallest A_i and build initial heap
        for (int i = 0; i < k; ++i) {
            sum_b += items[i].second;
            pq.push(items[i].second);
        }

        result = (long long)items[k - 1].first * sum_b;

        // Try replacing the max in heap with smaller A_i but better B_i
        for (int i = k; i < n; ++i) {
            if (items[i].second > pq.top()) {
                sum_b -= pq.top();
                pq.pop();
                pq.push(items[i].second);
                sum_b += items[i].second;
                result = min(result, (long long)items[i].first * sum_b);
            }
        }

        cout << result << "\n";
    }

    return 0;
}