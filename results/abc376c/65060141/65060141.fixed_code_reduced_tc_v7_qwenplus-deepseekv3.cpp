#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];
int main(){
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n-1;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n-1);
    ll i=0,j=0,cnt=0;
    vector<ll> unmatched;
    while(i<n && j<n-1){
        if(b[j]>=a[i]){
            i++;
            j++;
        } else {
            j++;
        }
    }
    if(i==n){
        cout<<0;
        return 0;
    }
    if(n-i>1){
        cout<<-1;
        return 0;
    }
    cout<<a[i];
    return 0;
}