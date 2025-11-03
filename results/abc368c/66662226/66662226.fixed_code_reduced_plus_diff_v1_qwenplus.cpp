#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll t = 0;
    int idx = 0;
    
    while (idx < n) {
        t++;
        if (h[idx] > 0) {
            if (t % 3 == 0) {
                h[idx] -= 3;
            } else {
                h[idx]--;
            }
            if (h[idx] <= 0) {
                idx++;
            }
        }
    }
    
    cout << t << endl;
}