#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    vector<ll> h(n);
    for(int i=0;i<n;i++) {
        cin>>h[i];
    }
    sort(h.begin(), h.end());
    reverse(h.begin(), h.end());
    for(ll val:h){
        ans+=(val/3)*3;
        val%=3;
        while(val>0){
            if(tri==3){
                tri=1;
                val-=3;
                ans++;
            }else{
                tri++;
                ans++;
            }
            val--;
        }
    }
    cout<<ans;
}