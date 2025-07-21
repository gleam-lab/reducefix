#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

ll solve(int n, int k, vector<ll>& a, vector<ll>& b) {
    vector<pair<ll, ll>> ab(n);
    for(int i = 0; i < n; ++i)
        ab[i] = {a[i], b[i]};
    
    sort(ab.begin(), ab.end());
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0, ans = inf;
    
    for(int i = 0; i < n; ++i) {
        pq.push(ab[i].second);
        sum += ab[i].second;
        
        if(pq.size() > k)
            sum -= pq.top(), pq.pop();
        
        if(i >= k - 1)
            ans = min(ans, sum * ab[i].first);
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        
        cout << solve(n, k, a, b) << '\n';
    }
    
    return 0;
}