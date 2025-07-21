#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    int i,j,x,y,z,t;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i];
    b[0]=1;
    for(i=1;i<n*2;i++)
    {
        if(i>n)  // Changed from i>=n to i>n to properly handle window
            b[d[i-n]%m]--;
        d[i]=(d[i-1]+a[i])%m;  // Take modulo early to prevent overflow
        sum+=b[d[i]%m];
        if(i<=n)  // Changed from i<n to i<=n to properly initialize
            b[d[i]%m]++;
    }
    cout<<sum;
    return 0;
}