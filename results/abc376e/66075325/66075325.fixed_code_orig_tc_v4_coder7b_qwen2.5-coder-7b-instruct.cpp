#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define int long long

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].first >> ab[i].second;
        }
        
        // Sort based on the first element of pairs
        sort(ab.begin(), ab.end());
        
        int ans = LLONG_MAX;
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < n; ++i) {
            sum += ab[i].second;
            pq.push(ab[i].second);
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if (pq.size() == k) {
                ans = min(ans, (ab[i].first * sum));
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}