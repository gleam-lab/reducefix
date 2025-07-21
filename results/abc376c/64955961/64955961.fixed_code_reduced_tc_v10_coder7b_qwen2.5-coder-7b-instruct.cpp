#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n-1; ++i) cin >> b[i];

    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    ll j = 0, max_size = 0;

    // Iterate through toys to determine the maximum size needed
    for(ll i = 0; i < n; ++i) {
        while(j < n-1 && a[i] > b[j]) {
            max_size = max(max_size, b[j]);
            ++j;
        }
        if(i == n-1) max_size = max(max_size, a[i]);
    }

    // Check if we have enough boxes with sufficient size
    if(j >= n-1) cout << max_size << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}