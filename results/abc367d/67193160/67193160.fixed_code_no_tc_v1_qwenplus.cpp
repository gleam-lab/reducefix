#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long sum;
int a[N*2],d[N*2];
map<int,int> b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    
    d[0]=0;
    b[0]=1;
    
    for(int i=1;i<n*2;i++){
        d[i]=(d[i-1]+a[i])%m;
        if(d[i]<0) d[i]+=m; // Handle negative modulo
        
        // Count pairs where j < i and (prefix[i]-prefix[j])%m==0
        // This means prefix[i]%m == prefix[j]%m
        if(i<n) sum+=b[d[i]]; // Only count valid subarrays (length <= n)
        
        if(i<n) b[d[i]]++;
    }
    
    cout<<sum;
    return 0;
}