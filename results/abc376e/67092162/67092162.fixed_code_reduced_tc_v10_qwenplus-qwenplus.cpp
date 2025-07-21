#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN = 2e5 + 5;
int t, n, k;
ll a[maxN], b[maxN];
pair<ll, ll> p[maxN];

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.first < p2.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n >> k;
        priority_queue<ll> q;
        ll sum = 0;
        ll ans = LLONG_MAX;
        
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        for (int i = 0; i < n; i++) {
            p[i] = {a[i], b[i]};
        }
        
        sort(p, p + n, cmp);
        
        // Initialize with first K elements
        sum = 0;
        for (int i = 0; i < k; i++) {
            sum += p[i].second;
            q.push(p[i].second);
        }
        
        ans = p[k-1].first * sum;
        
        // Try replacing largest B in subset with smaller ones
        for (int i = k; i < n; i++) {
            if (p[i].second < q.top()) {
                sum -= q.top();
                q.pop();
                q.push(p[i].second);
                sum += p[i].second;
            }
            ans = min(ans, p[i].first * sum);
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}