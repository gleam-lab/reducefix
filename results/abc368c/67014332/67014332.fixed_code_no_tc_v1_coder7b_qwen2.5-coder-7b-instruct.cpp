#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, ans=0, tri=1;
    cin>>n;
    vector<ll> health(n);
    for(int i=0;i<n;i++)
        cin>>health[i];
    sort(health.begin(), health.end());
    int i=0;
    while(i<n){
        if(health[i] == 0)
            i++;
        else{
            if(tri==3){
                tri=1;
                ans+=3;
                health[i]--;
            }else{
                tri++;
                ans++;
                health[i]--;
            }
            if(health[i]==0)
                i++;
        }
    }
    cout<<ans;
}