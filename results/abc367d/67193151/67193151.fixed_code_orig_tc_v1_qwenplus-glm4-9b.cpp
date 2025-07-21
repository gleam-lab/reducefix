#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n*2;i++)
    {
        if(i<n)
            d[i]=d[i-1]+a[i];
        else
            d[i]=d[i-1]+a[i-n]+n;  // Ensure correct wrap-around by adding n

        int index = (d[i] % m + m) % m;  // Correct modulo and wrap-around
        b[index]++;
    }
    
    // Calculate the final sum based on counts in b
    for(int i=0; i<m; i++)
    {
        if(b[i] > 0)
            sum += b[i];  // Each count contributes to the sum
    }
    
    cout<<sum;
    return 0;
}