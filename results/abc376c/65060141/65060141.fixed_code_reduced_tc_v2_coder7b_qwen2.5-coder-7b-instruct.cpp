#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;
ll a[N],b[N];

bool check(ll x){
    sort(a+1,a+N+1);
    sort(b+1,b+N);
    int j=0;
    for(int i=N;i>=1;i--){
        if(j==N-1) return true;
        if(b[j]<a[i]) return false;
        else j++;
    }
    return true;
}

int main(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for(ll i=1;i<n;i++){
        cin>>b[i];
    }

    ll l=1,r=*max_element(a+1,a+n+1),mid,ans=-1;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else l=mid+1;
    }
    
    cout<<ans;
    return 0;
}