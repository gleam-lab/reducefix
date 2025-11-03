#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
long long sum;
int a[2*N],d[2*N];
map<int,int> b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    // Create doubled array for circular subarrays
    for(int i=1;i<=n;i++)
        a[i+n]=a[i];
    
    // Prefix sum modulo m, count frequency of remainders
    d[0]=0;
    b[0]=1; // Important: empty prefix has sum 0
    
    for(int i=1;i<2*n;i++)
    {
        d[i]=(d[i-1]+a[i])%m;
        // Normalize to non-negative remainder
        if(d[i]<0) d[i]+=m;
        
        // Count how many previous prefixes have same remainder
        // These form valid subarrays with sum divisible by m
        sum+=b[d[i]];
        
        // Only add prefixes that start in the first half (original array)
        // and end at position <= 2n-1 (within doubled array)
        if(i<n)
            b[d[i]]++;
    }
    
    cout<<sum;
    return 0;
}