#include<bits/stdc++.h>
using namespace std;
int n,q,x[200005],p[200005];
int sum[200005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
        sum[i]=sum[i-1]+p[i];
    }
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        int left=lower_bound(x+1,x+n+1,l)-x;
        int right=upper_bound(x+1,x+n+1,r)-x-1;
        if(left>right) cout<<"0\n";
        else cout<<sum[right]-sum[left-1]<<"\n";
    }
    return 0;
}