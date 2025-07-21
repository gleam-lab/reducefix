#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n,cnt=0,ans=0,mx=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<n;i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n);
    ll l=n,r=n-1;
    while(l>=1 && r>=1){
        if(b[r]>=a[l]){
            r--;
            l--;
        }
        else{
            cnt++;
            mx=max(mx,a[l]);
            l--;
        }
    }
    if(cnt==1){
        cout<<max(mx,b[1]);
    }
    else if(cnt>1){
        cout<<-1;
    }
    return 0;
}