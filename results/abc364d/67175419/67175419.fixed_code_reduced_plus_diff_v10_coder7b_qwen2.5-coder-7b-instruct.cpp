#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q;
ll a[N],b[N],k[N];
void solve(){
    sort(a+1,a+n+1);
    for(int i=1;i<=q;i++){
        cin>>b[i]>>k[i];
        int l=1,r=n;
        while(l<r){
            int m=(l+r)>>1;
            if((a[m]-b[i])*(a[m]-b[i])+(a[m+1]-b[i])*(a[m+1]-b[i])<2*k[i]*k[i])
                r=m;
            else 
                l=m+1;
        }
        cout<<(a[l]-b[i])*(a[l]-b[i])+(a[l+1]-b[i])*(a[l+1]-b[i])<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    solve();
    return 0;
}