#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pb push_back
#define mp make_pair
#define MOD 1e9+7
#define INF LLONG_MAX

typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    
    // Sort the array to facilitate finding min/max differences
    sort(a.begin(), a.end());
    
    // Initialize variables to store the result and temporary values
    ll ans = INF;
    
    // Iterate through possible ways to remove k elements
    for(int i = 0; i <= k; ++i){
        // Calculate the difference between max and min after removing i smallest and k-i largest elements
        ll diff = a[min(k, n-1)] - a[max(0, i)];
        ans = min(ans, diff);
    }
    
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}