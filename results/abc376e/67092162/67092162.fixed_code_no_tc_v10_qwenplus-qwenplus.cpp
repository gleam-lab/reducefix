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
        for (int i = 0; i < n; ++i) cin >> items[i].first;
        for (int i = 0; i < n; ++i) cin >> items[i].second;
        
        // Sort by A_i ascending
        sort(items.begin(), items.end());

        // Minimize sum * max_A using a sliding window approach
        priority_queue<int> max_heap; // To keep track of largest B's we might remove
        long long sum_b = 0;
        long long min_result = 1e18;

        // First, take the K smallest A values
        for (int i = 0; i < k; ++i) {
            sum_b += items[i].second;
            max_heap.push(items[i].second);
        }
        min_result = (long long)items[k - 1].first * sum_b;

        // Slide through the rest
        for (int i = k; i < n; ++i) {
            if (items[i].second < max_heap.top()) {
                sum_b -= max_heap.top();
                max_heap.pop();
                sum_b += items[i].second;
                max_heap.push(items[i].second);
            }
            min_result = min(min_result, (long long)items[i].first * sum_b);
        }

        cout << min_result << "\n";
    }

    return 0;
}