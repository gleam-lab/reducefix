#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // dp_e: max sum ending at even number of elements picked
    // dp_o: max sum ending at odd number of elements picked
    ll dp_e = 0, dp_o = -1, temp;

    rep(i,n)
    {
        temp = dp_e;
        // If we don't pick current element, dp_e remains same
        // If we pick current element and previous was odd count: dp_o + a[i]
        dp_e = max(dp_e, dp_o + 2 * a[i]);  // Extend odd sequence by adding element twice
        // If we don't pick current element, dp_o remains same
        // If we pick current element and previous was even count: dp_e_prev + a[i]
        dp_o = max(dp_o, temp + a[i]);      // Extend even sequence by adding one element
    }

    cout << max(dp_e, dp_o) << endl;
}