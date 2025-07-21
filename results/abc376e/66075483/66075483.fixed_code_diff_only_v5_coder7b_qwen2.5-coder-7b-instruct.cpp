#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t,n,k,a[200005],b[200005];

    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];

        vector<pair<ll,ll>> vec(n);
        for(int i=0;i<n;i++){
            vec[i]={a[i],b[i]};
        }

        sort(vec.begin(),vec.end());
        
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll sum=0,ans=LLONG_MAX;

        for(int i=0;i<k-1;i++){
            pq.push(vec[i].second);
            sum+=vec[i].second;
        }

        for(int i=k-1;i<n;i++){
            pq.push(vec[i].second);
            sum+=vec[i].second;
            ans=min(ans,sum*vec[i].first);
            sum-=pq.top();
            pq.pop();
        }

        cout<<ans<<endl;
    }
    
    return 0;
}