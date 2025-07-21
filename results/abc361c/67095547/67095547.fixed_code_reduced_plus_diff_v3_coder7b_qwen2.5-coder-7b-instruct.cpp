#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vi vector<ll>

void solve() {
    ll n, k;
    cin >> n >> k;
    vi arr(n);
    for(auto &i: arr) cin >> i;
    
    sort(arr.begin(), arr.end());
    
    // Calculate the difference between the largest and smallest elements after removing K elements
    ll min_diff = LLONG_MAX;
    for(ll i = 0; i <= k; i++) {
        min_diff = min(min_diff, arr[n-k+i] - arr[i]);
    }
    
    cout << min_diff << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}