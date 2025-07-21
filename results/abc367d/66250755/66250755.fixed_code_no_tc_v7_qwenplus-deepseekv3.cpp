#include<bits/stdc++.h>
using namespace std;
int n,m,a[400005],t[1000005]={0},ans=0,w[400005];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=m;
        a[i+n]=a[i];
    }
    
    w[0] = 0;
    for(int i=1;i<=2*n;i++)
    {
        w[i] = (w[i-1] + a[i]) % m;
    }
    
    // Initialize the map with w[0] = 0
    t[0] = 1;
    
    for(int i=1;i<=2*n;i++)
    {
        if(i > n)
        {
            int prev = w[i-n];
            t[prev]--;
        }
        if(i >= n)
        {
            ans += t[w[i]];
        }
        t[w[i]]++;
    }
    
    cout<<ans;
    return 0;
}