#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e9+7;

ll n, m, cnt[2][2*N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        ll x,y,d; cin >> x >> y;
        d = (x+y)%2;
        cnt[d][x-y+N]++;
        cnt[d][x+y]++;
    }

    ll ans = n*n;
    for(int i=1;i<=2*N;i++){
        ans -= (cnt[0][i]*cnt[1][i]);
    }
    
    cout << ans << "\n";

    return 0;
}