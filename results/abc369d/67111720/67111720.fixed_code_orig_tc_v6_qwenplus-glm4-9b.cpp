#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll dp_even = 0, dp_odd = 0; // Initialize the two conditions
    rep(i,n)
    {
        ll dp_even_temp = dp_even; // Copy the previous dp_even value
        // Update the conditions based on the current item
        dp_even = max(dp_odd + a[i], dp_even_temp);
        dp_odd = max(dp_even_temp + a[i], dp_odd);
    }

    cout << max(dp_even, dp_odd) << endl;
}