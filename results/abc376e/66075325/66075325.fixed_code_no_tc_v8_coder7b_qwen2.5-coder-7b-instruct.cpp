#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>>a(n),b(n);
        for(int i=0;i<n;++i){
            cin>>a[i].first;
            a[i].second=i;
        }
        for(int i=0;i<n;++i){
            cin>>b[i].first;
            b[i].second=i;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long ans=LLONG_MAX,sum=0;
        for(int i=n-k;i<n;++i){
            sum+=b[i].first;
            ans=min(ans,(long long)a[n-1-i].first*sum);
        }
        cout<<ans<<'\n';
    }
}