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
        
        // Read input into vectors
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        // Sort based on the first element of the pairs
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Priority queue to keep track of the sum of B values
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        
        // Initialize the sliding window
        for (int i = 0; i < k; ++i) {
            pq.push(b[a[i].second].first);
            sum += b[a[i].second].first;
        }
        
        long long ans = sum * a[k - 1].first;
        
        // Slide the window across the array
        for (int i = k; i < n; ++i) {
            pq.push(b[a[i].second].first);
            sum += b[a[i].second].first;
            sum -= pq.top();
            pq.pop();
            ans = min(ans, sum * a[i].first);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}