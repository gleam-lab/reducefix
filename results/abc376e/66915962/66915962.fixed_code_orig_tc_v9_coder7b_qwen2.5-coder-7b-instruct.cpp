#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> ab(n);
        for(int i = 0; i < n; ++i) {
            cin >> ab[i].first >> ab[i].second;
        }
        
        // Sort based on the ratio of A_i / B_i
        sort(ab.begin(), ab.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return (double)a.first / a.second > (double)b.first / b.second;
        });
        
        int ans = INT_MAX;
        int sumB = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i < k; ++i) {
            sumB += ab[i].second;
            pq.push(-ab[i].first);
        }
        
        ans = min(ans, -pq.top() * sumB);
        
        for(int i = k; i < n; ++i) {
            sumB += ab[i].second - (-pq.top()); // Remove the largest element in pq
            pq.pop();
            pq.push(-ab[i].first); // Add the current element
            
            ans = min(ans, -pq.top() * sumB);
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}