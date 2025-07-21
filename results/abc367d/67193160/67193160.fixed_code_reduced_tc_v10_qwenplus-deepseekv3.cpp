#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long n,m,k,sum,cnt,a[N],d[N];
unordered_map<long long,long long> b;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    b[0]=1;
    for(int i=1;i<2*n;i++)
    {
        d[i]=d[i-1]+a[i];
        if(i>=n)
        {
            long long mod_val=(d[i-n])%m;
            if(mod_val<0) mod_val+=m;
            b[mod_val]--;
        }
        long long mod_val=d[i]%m;
        if(mod_val<0) mod_val+=m;
        sum+=b[mod_val];
        if(i<n)
        {
            b[mod_val]++;
        }
    }
    cout<<sum;
    return 0;
}