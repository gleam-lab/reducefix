//<<In the name of Allah, The Most Gracious and The Most Merciful>>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) 
        cin >> a[i];
    for(ll i = 0; i < n - 1; i++) 
        cin >> b[i];
    
    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll j = 0;
    for(ll i = n - 1; i >= 0 && j < n - 1; --i) {
        if(a[i] > b[j]) {
            ++j;
        }
    }
    
    if(j == n - 1) 
        cout << a[n - 1] << endl;
    else 
        cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}