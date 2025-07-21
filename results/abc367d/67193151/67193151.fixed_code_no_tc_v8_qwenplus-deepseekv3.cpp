#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,a[N],prefix[2*N],cnt[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i]; // create circular array
    }
    
    // Compute prefix sums for circular array
    prefix[0]=0;
    for(int i=1;i<=2*n;i++)
        prefix[i]=(prefix[i-1]+a[i])%m;
    
    cnt[0]=1; // empty prefix sum
    long long total=0;
    
    // Sliding window of size n
    for(int i=1;i<=2*n;i++)
    {
        if(i>n)
        {
            int rem=prefix[i-n]%m;
            cnt[rem]--;
        }
        total+=cnt[prefix[i]];
        if(i<=n)
            cnt[prefix[i]]++;
    }
    
    cout<<total;
    return 0;
}