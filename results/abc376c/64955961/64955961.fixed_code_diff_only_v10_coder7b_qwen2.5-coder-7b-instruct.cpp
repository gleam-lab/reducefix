#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; ++i) 
        cin >> a[i];
    for(ll i = 0; i < n - 1; ++i) 
        cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll idx = 0;
    while(idx < n && a[idx] <= b[idx]) 
        ++idx;

    if(idx == n) 
        cout << a.back() + 1 << endl;
    else 
        cout << a[idx] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}