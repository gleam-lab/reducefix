#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    // Initialize dp arrays to handle even and odd indexed elements separately
    vector<ll> dp_e(n, 0), dp_o(n, -1);

    rep(i,n)
    {
        if (i % 2 == 0) { // Even index
            dp_e[i] = max((i > 0 ? dp_o[i-1] : -1) + 2 * a[i], dp_e[i-1]);
            dp_o[i] = max(dp_o[i-1], dp_e[i-1] + a[i]);
        } else { // Odd index
            dp_o[i] = max((i > 0 ? dp_e[i-1] : -1) + 2 * a[i], dp_o[i-1]);
            dp_e[i] = max(dp_e[i-1], dp_o[i-1] + a[i]);
        }
    }

    cout << max(*max_element(dp_e.begin(), dp_e.end()), *max_element(dp_o.begin(), dp_o.end())) << endl;
}