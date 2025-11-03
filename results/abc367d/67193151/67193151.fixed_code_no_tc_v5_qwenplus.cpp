#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long sum;
int a[N*2],d[N*2];
map<int,int> b;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],a[i+n]=a[i];
    
    d[0]=0;
    b[0]=1;
    
    for(int i=1;i<2*n;i++)
    {
        d[i]=(d[i-1]+a[i])%m;
        if(d[i]<0) d[i]+=m; // Handle negative modulo
        
        // Count pairs ending at position i
        sum+=b[d[i]];
        
        // Add current prefix to map if it's in the first occurrence window
        if(i<n)
            b[d[i]]++;
    }
    
    cout<<sum;
    return 0;
}