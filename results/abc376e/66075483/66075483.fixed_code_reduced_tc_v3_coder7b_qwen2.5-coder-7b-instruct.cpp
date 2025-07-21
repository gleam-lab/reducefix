#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,n,k,a[200005],b[200005],c[200005],d[200005];
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            v[i]={a[i],i};
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            c[v[i].second]=i+1;
        }
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(b,b+n);
        long long sum=0,ma=0,mi=1e9;
        for(int i=0;i<k-1;i++){
            sum+=b[i];
            ma=max(ma,(long long)a[c[b[i]]]);
        }
        mi=min(mi,sum*a[c[b[k-1]]]);
        for(int i=k;i<n;i++){
            sum=sum-b[i-k]+b[i];
            ma=max(ma,(long long)a[c[b[i]]]);
            mi=min(mi,sum*a[c[b[i]]]);
        }
        cout<<mi<<endl;
    }
    return 0;
}