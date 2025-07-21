#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;
    for (ll h : H) {
        // For each enemy, determine how many attacks are needed considering the pattern:
        // At time t: if t % 3 == 0 => attack of 3 damage, else 1 damage
        // So in every group of 3 attacks, we deal 1+1+3 = 5 damage
        ll full_cycles = h / 5;
        ll remaining = h % 5;

        T += full_cycles * 3;
        
        if (remaining > 0) T += 1;
        if (remaining > 1) T += 1;
        if (remaining > 3) T += 1;
    }

    cout << T << endl;
}