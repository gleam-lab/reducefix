#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll max_a = -1, sum_b = 0;
    for(int i=0;i<k;i++){
        pq.push(b[i]);
        sum_b += b[i];
        max_a = max(max_a, a[i]);
    }
    ll res = max_a * sum_b;
    for(int i=k;i<n;i++){
        sum_b -= pq.top();
        pq.pop();
        sum_b += b[i];
        pq.push(b[i]);
        max_a = max(max_a, a[i]);
        res = min(res, max_a * sum_b);
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}