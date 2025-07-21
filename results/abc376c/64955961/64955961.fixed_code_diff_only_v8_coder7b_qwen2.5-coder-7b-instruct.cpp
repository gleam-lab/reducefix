#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n - 1; i++) cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    // Check if the largest toy can fit in any of the available boxes
    bool possible = false;
    for(ll i = 0; i < n - 1; i++)
    {
        if(a.back() <= b[i]) 
        {
            possible = true;
            break;
        }
    }
    
    // If the largest toy cannot fit in any existing box, we need a new box
    if(!possible && a.back() > b[n - 2]) cout << -1 << endl;
    else cout << *max_element(a.begin(), a.end()) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}