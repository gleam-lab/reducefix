#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll i = n-1, j = n-2, mx = 0;
    while(i >= 0 && j >= 0){
        if(a[i] <= b[j]){
            i--; j--;
        }else{
            mx = max(mx, a[i]);
            i--;
        }
    }
    if(i == 0) cout << mx << endl;
    else cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}