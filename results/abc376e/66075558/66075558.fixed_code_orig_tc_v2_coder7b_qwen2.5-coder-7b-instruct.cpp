#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on A_i in descending order
        sort(a.begin(), a.end(), greater<pair<int, int>>());
        // Sort based on B_i in ascending order
        sort(b.begin(), b.end());
        
        // Priority queue to keep track of sums of B_i values
        priority_queue<int, vector<int>, greater<int>> pq;
        int current_sum = 0;
        
        // Add first K elements of B_i to the priority queue and calculate their sum
        for (int i = 0; i < k; ++i) {
            pq.push(b[i].first);
            current_sum += b[i].first;
        }
        
        // Initialize result as the initial product
        int result = current_sum * a[k - 1].first;
        
        // Iterate through the remaining elements
        for (int i = k; i < n; ++i) {
            // Remove the smallest element from the priority queue
            current_sum -= pq.top();
            pq.pop();
            
            // Add the next largest element from B_i to the priority queue
            pq.push(b[i].first);
            current_sum += b[i].first;
            
            // Update the result if the new product is smaller
            result = min(result, current_sum * a[i].first);
        }
        
        cout << result << '\n';
    }
    
    return 0;
}