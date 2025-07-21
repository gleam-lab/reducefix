#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<n;i++){
        cin>>b[i];
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n);
    ll i=n,j=n-1;
    ll cnt=0;
    ll mx=0;
    while(i>=1 && j>=1){
        if(b[j]>=a[i]){
            j--;
            i--;
        } else {
            cnt++;
            mx=max(mx,a[i]);
            i--;
        }
    }
    while(i>=1){
        cnt++;
        mx=max(mx,a[i]);
        i--;
    }
    if(cnt>1){
        cout<<-1;
    } else {
        cout<<mx;
    }
    return 0;
}