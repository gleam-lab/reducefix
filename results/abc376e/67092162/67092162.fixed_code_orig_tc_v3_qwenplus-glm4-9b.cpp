#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;  // Sort primarily by A_i in descending order
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a_b;
        
        // Read A and B and store as pairs
        for (int i = 0; i < n; ++i) {
            int a_i, b_i;
            cin >> a_i >> b_i;
            a_b.emplace_back(a_i, b_i);
        }
        
        // Sort pairs by A_i in descending order
        sort(a_b.begin(), a_b.end(), compare);
        
        vector<int> prefix_sum(n + 1, 0);
        
        // Calculate prefix sums of B
        for (int i = 0; i < n; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + a_b[i].second;
        }
        
        int min_value = INT_MAX;
        
        // Evaluate the expression using a sliding window
        for (int i = 0; i <= n - k; ++i) {
            int max_a = a_b[i].first; // max A_i in the current window
            int sum_b = prefix_sum[i + k] - prefix_sum[i]; // sum B_i in the current window
            min_value = min(min_value, max_a * sum_b);
        }
        
        cout << min_value << endl;
    }
    
    return 0;
}