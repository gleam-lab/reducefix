#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define vi vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define MOD 1e9+7
#define INF LLONG_MAX
#define all(x) x.begin(), x.end()

void solve() {
    ll n, k; cin >> n >> k;
    vi a(n);
    for(ll &i:a) cin >> i;
    
    // Sort the array
    sort(all(a));
    
    // Calculate the difference between max and min after removing k elements
    ll ans = a[n-k-1] - a[k];
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}