#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; ++i) {
            cin >> ab[i].first >> ab[i].second;
        }
        
        sort(ab.begin(), ab.end());
        
        ll sum_b = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; ++i) {
            sum_b += ab[i].second;
            pq.push(-ab[i].second);
        }
        
        ll result = sum_b * ab[k - 1].first;
        
        for (int i = k; i < n; ++i) {
            sum_b += ab[i].second + pq.top();
            pq.pop();
            pq.push(-ab[i].second);
            
            result = min(result, sum_b * ab[i].first);
        }
        
        cout << result << '\n';
    }
    
    return 0;
}