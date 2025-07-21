#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum_b = 0;
        for(int i = 0; i < k - 1; ++i) {
            pq.push(b[i]);
            sum_b += b[i];
        }

        ll ans = LLONG_MAX;
        for(int i = k - 1; i < n; ++i) {
            ans = min(ans, (a[i] * (sum_b + b[i])));
            
            if(!pq.empty() && pq.top() > b[i]) {
                sum_b -= pq.top();
                sum_b += b[i];
                pq.pop();
                pq.push(b[i]);
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}