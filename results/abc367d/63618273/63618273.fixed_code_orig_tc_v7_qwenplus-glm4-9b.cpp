#include<bits/stdc++.h>

using namespace std;
using ll=long long;
typedef pair<int, int>PII;
const int N=2e5+10,mod=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--){
        int n,M;
        cin>>n>>M;
        vector<int>a(n+10);
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        vector<int>sum(n+2);
        sum[0] = 0;
        for(int i=1; i<=n; i++){
            sum[i+1] = (sum[i] + a[i]) % mod;
        }
        map<int, int> mp;
        ll ans=0;
        for(int i=1; i<=n; i++){
            ans += mp[(sum[i] + M - sum[i-1]) % mod];
            mp[sum[i]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}