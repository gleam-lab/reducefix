#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pii> a(n), b(n);
        
        // Read and store pairs
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort by value, keeping original indices
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Min-heap to keep track of sums of B values
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, res = LLONG_MAX;
        
        // Initialize the heap with first K elements
        for (int i = 0; i < k; ++i) {
            sum += b[a[i].second].first;
            pq.push(b[a[i].second].first);
        }
        
        // Calculate initial result
        res = (long long)a[k-1].first * sum;
        
        // Iterate through the rest of the elements in A
        for (int i = k; i < n; ++i) {
            // Remove the smallest element from the heap
            sum -= pq.top();
            pq.pop();
            // Add the new element to the heap
            sum += b[a[i].second].first;
            pq.push(b[a[i].second].first);
            // Update the result
            res = min(res, (long long)a[i].first * sum);
        }
        
        // Output the result
        cout << res << endl;
    }
    
    return 0;
}