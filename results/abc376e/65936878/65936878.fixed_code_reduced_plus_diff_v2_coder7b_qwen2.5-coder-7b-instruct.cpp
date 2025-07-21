#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<ll, ll>> pairs(n);
        
        // Read input into pairs of (A_i, B_i)
        for (int i = 0; i < n; ++i) {
            cin >> pairs[i].first >> pairs[i].second;
        }
        
        // Sort pairs by B_i in descending order to prioritize larger B_i values
        sort(pairs.begin(), pairs.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.second > b.second;
        });
        
        // Min-heap to keep track of the smallest A_i values
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll totalSum = 0;
        
        // Select the top k pairs and initialize the heap
        for (int i = 0; i < k; ++i) {
            pq.push(pairs[i].first);
            totalSum += pairs[i].second;
        }
        
        // Initialize the result with the current maximum A_i * totalSum
        ll result = pq.top() * totalSum;
        
        // Iterate through the remaining pairs
        for (int i = k; i < n; ++i) {
            // Remove the smallest A_i from the heap
            pq.pop();
            
            // Add the new A_i to the heap
            pq.push(pairs[i].first);
            
            // Update the total sum
            totalSum -= pq.top();
            totalSum += pairs[i].second;
            
            // Calculate the new result
            result = min(result, pq.top() * totalSum);
        }
        
        // Output the result
        cout << result << '\n';
    }

    return 0;
}