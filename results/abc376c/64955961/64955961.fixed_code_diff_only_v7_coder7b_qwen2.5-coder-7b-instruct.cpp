#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n - 1);
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n - 1; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll max_a = *max_element(a.begin(), a.end());
    ll min_b = *min_element(b.begin(), b.end());

    if(max_a > min_b){
        cout << -1 << endl;
    } else {
        cout << min_b << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}