#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define int long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        // Sort A in descending order based on the first element of the pair
        sort(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        });
        
        // Sort B in ascending order
        sort(b.begin(), b.end());
        
        // Min heap to store the sums of subsets of B
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(0);
        
        long long ans = LLONG_MAX;
        
        for (int i = 0; i < n; ++i) {
            int ai = a[i].first;
            int idx = a[i].second;
            
            // Remove elements from the heap that exceed the current index
            while (!pq.empty() && pq.top() > idx) {
                pq.pop();
            }
            
            // Calculate new sums and update the answer
            while (!pq.empty()) {
                long long sum = pq.top();
                pq.pop();
                
                if (sum + b[idx] <= n) {
                    pq.push(sum + b[idx]);
                }
                
                ans = min(ans, ai * (sum + b[idx]));
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}