#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    
    vector<ll> v(n);
    for(ll &x: v)
        cin >> x;

    ll ans = 0, t = 0;
    for(auto x: v) {
        while(x > 0) {
            ++t;
            if(t % 3 == 0)
                x -= 3;
            else
                --x;
            
            ++ans;
        }
    }

    cout << ans << "\n";
    return 0;
}