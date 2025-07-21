#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (long long i=0;i < (n); i++)
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll t = 0, total_damage = 0;
    while(true){
        bool done = true;
        rep(i, n){
            if(h[i] > 0){
                done = false;
                ++t;
                if(t % 3 == 0){
                    h[i] -= 3;
                }else{
                    --h[i];
                }
            }
        }
        if(done) break;
    }

    cout << t << endl;
    return 0;
}