#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i = 0; i < n; i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll dp_e = 0, dp_o = -1; // dp_e represents the maximum value of even indexed subarrays, dp_o represents the maximum value of odd indexed subarrays

    for (int i = 0; i < n; i++)
    {
        ll new_dp_e = max(dp_o + 2 * a[i], dp_e); // Calculate new dp_e considering the current element can be added to an odd indexed subarray or extended an even indexed subarray
        dp_e = new_dp_e;

        ll new_dp_o = max(dp_e, dp_o + 2 * a[i]); // Calculate new dp_o considering the current element can be added to an even indexed subarray or extended an odd indexed subarray
        dp_o = new_dp_o;
    }

    cout << max(dp_e, dp_o) << endl; // The result is the maximum of both dp_e and dp_o
}