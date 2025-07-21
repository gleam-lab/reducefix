#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for(ll i = 0; i < n-1; ++i)
    {
        cin >> b[i];
    }
    
    // Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // Initialize variables
    ll i = n - 1, j = n - 2, ans = INT_MAX;
    while(i >= 0 && j >= 0)
    {
        if(a[i] <= b[j]) 
        {
            --i;
        } 
        else 
        {
            ans = min(ans, a[i]);
            --j;
        }
    }

    // If we couldn't place any toy, return -1
    if(ans == INT_MAX) cout << "-1" << endl;
    else cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}