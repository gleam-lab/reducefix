#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, ans=0, tri=1;
    cin>>n;
    vector<ll> health(n);
    for(ll i=0;i<n;i++) {
        cin>>health[i];
    }
    sort(health.begin(), health.end());
    for(auto &h : health){
        if(h == 0) continue;
        if(h <= tri){
            ans += (h+2)/3;
            h -= (h+2)/3 * 3;
        } else{
            ans += h / 3;
            h %= 3;
            if(h != 0){
                ans++;
            }
        }
        if(tri == 2){
            tri = 1;
        } else{
            tri++;
        }
    }
    cout<<ans;
    return 0;
}