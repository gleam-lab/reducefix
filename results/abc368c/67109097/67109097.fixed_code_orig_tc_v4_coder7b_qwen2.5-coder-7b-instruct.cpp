#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];

    long long ans = 0, mod = 3;

    for(int i=n;i>=1;i--){
        if(v[i]>0){
            long long x = v[i]/mod;
            ans += x*(mod-1);

            if(v[i]%mod==0)
                ans += x;
            else{
                ans += x+1;
                v[i] %= mod;
                while(v[i]){
                    if(v[i]>=mod)
                        v[i]-=mod;
                    else{
                        ans += v[i];
                        v[i]=0;
                    }
                }
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}