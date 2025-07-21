#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    for(int i=0;i<n;i++) {
        ll h;
        cin>>h;
        ans+=(h+2)/3;
    }
    cout<<ans;
}