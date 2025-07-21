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
    ll i=1,j=1;
    ll cnt=0;
    ll mx=0;
    while(i<=n && j<n){
        if(b[j]>=a[i]){
            i++;
            j++;
        } else {
            if(cnt==0){
                mx=a[i];
                cnt++;
                i++;
            } else {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    if(i<=n){
        if(cnt==0){
            mx=a[n];
        } else if(i==n){
            mx=max(mx,a[n]);
        } else {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<mx<<endl;
    return 0;
}