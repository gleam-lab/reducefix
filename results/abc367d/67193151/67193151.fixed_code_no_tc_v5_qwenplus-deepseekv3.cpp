#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],prefix[2*N],cnt[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i]; // Make it circular by doubling the array
    }
    
    long long sum=0;
    cnt[0]=1; // Initialize for empty prefix
    
    for(int i=1;i<=2*n;i++)
    {
        prefix[i]=(prefix[i-1]+a[i])%m;
        if(i>=n)
        {
            // Remove the contribution from the prefix that's now out of window
            if(i>n) cnt[prefix[i-n]]--;
            sum+=cnt[prefix[i]];
        }
        if(i<n)
        {
            cnt[prefix[i]]++;
        }
    }
    
    cout<<sum;
    return 0;
}