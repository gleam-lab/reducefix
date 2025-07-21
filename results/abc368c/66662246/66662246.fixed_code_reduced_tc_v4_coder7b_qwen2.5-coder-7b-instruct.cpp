#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll ans = 0;
    rep(i, n)
    {
        while (a[i] > 0)
        {
            ans++;
            if (ans % 3 == 0)
            {
                a[i] -= 3;
            }
            else
            {
                a[i]--;
            }
        }
    }
    cout << ans << endl;
}