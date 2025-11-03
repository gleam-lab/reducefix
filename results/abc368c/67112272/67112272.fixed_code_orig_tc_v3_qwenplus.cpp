#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    int n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    
    ll T = 0;
    ll i = 0;
    
    while (i < n) {
        T++;
        if (h[i] > 0) {
            if (T % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i]--;
            }
            if (h[i] <= 0) {
                i++;
            }
        }
    }
    
    cout << T << endl;
}