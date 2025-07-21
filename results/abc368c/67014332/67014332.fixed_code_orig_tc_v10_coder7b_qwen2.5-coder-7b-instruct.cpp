#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, ans=0, tri=1;
    cin>>n;
    vector<ll> h(n);
    for(int i=0;i<n;i++) {
        cin>>h[i];
    }
    priority_queue<ll,vector<ll>,greater<ll>> pq(h.begin(),h.end());
    while(!pq.empty()) {
        ll top = pq.top();
        pq.pop();
        if(top%3 == 0){
            ans+=top/3;
        } else{
            ans+=(top/3 + 1);
        }
    }
    cout<<ans;
    return 0;
}