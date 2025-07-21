#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define arr array<int, 3>

const int N = 2e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<PII> ab(n);
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].fi;
    }
    for (int i = 0; i < n; ++i) {
        cin >> ab[i].se;
    }
    
    // Sort based on A[i]
    sort(ab.begin(), ab.end());
    
    // Initialize the variables
    int ans = INF;
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0;
    
    // Iterate through the sorted array to find the minimum value
    for (int i = 0; i < n; ++i) {
        pq.push(ab[i].se);
        sum += ab[i].se;
        
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        
        if (pq.size() == k) {
            ans = min(ans, ab[i].fi * sum);
        }
    }
    
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}