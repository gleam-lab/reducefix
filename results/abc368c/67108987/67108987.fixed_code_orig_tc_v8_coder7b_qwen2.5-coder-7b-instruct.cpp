#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin>>n;
    vector<ll> h(n+1), dp(n+1, LLONG_MAX);
    for(int i=1;i<=n;i++){
        cin>>h[i];
        if(h[i]==1){
            dp[i]=1;
        }
        else{
            dp[i]=min(dp[i], h[i]);
        }
    }

    for(int i=1;i<=n;i++){
        if(i>=2){
            dp[i]=min(dp[i], dp[i-1]+1);
        }
        if(i>=3){
            dp[i]=min(dp[i], dp[i-3]+3);
        }
    }

    cout<<dp[n]<<endl;
    return 0;
}