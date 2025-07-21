#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5+5;

pair<int,int> p[maxN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> p[i].first;
        for(int i = 0; i < n; i++) cin >> p[i].second;
        
        sort(p, p+n);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for(int i = n-k; i < n; i++) {
            pq.push(p[i].second);
            sum += p[i].second;
        }
        
        long long ans = p[n-1].first * sum;
        
        for(int i = n-k-1; i >= 0; i--) {
            if(pq.top() < p[i].second) {
                sum -= pq.top();
                pq.pop();
                sum += p[i].second;
                pq.push(p[i].second);
            }
            ans = min(ans, (long long)p[i].first * sum);
        }
        
        cout << ans << "\n";
    }
    return 0;
}