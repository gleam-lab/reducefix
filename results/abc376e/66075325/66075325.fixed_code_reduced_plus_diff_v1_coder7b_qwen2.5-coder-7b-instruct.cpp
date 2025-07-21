#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;

typedef pair<int,int> pii;

void solve(){
    int n,k; cin>>n>>k;
    vector<pii> arr(n);
    vector<pii> sum(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second=i;
    }
    for(int i=0;i<n;i++){
        cin>>sum[i].first;
        sum[i].second=i;
    }
    sort(arr.begin(),arr.end());
    sort(sum.begin(),sum.end());
    
    priority_queue<int,vector<int>,greater<int>> pq;
    int totalSum = 0;
    for(int i=0;i<k-1;i++){
        totalSum += sum[i].first;
        pq.push(sum[i].first);
    }
    int ans = INT_MAX;
    for(int i=k-1;i<n;i++){
        totalSum += sum[i].first;
        pq.push(sum[i].first);
        while(pq.size()>k){
            totalSum -= pq.top();
            pq.pop();
        }
        ans = min(ans,totalSum * arr[i].first);
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}