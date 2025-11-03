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
    
    ll T = 0;
    rep(i, n) {
        while (h[i] > 0) {
            T++;
            if (T % 3 == 0) {
                h[i] -= 3;
            } else {
                h[i]--;
            }
        }
    }
    cout << T << endl;
}