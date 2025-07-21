//<<In the name of Allah, The Most Gracious and The Most Merciful>>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    for (ll i = 0; i < n - 1; ++i)
        cin >> b[i];
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll c = 0, ans = a[0];
    for (ll i = n - 1, j = n - 2; i >= 0 && j >= 0;) {
        if (a[i] <= b[j]) {
            i--, j--;
        } else {
            c++, ans = max(ans, a[i]), i--;
        }
    }

    if (c > 1)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}