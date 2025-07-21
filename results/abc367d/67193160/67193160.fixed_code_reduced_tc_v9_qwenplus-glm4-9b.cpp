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
        cin>>a[i],a[i+n]=a[i]; // Extend the array a to size 2n
    b[0]=1;
    for(i=1;i<n*2;i++)
    {
        d[i] = d[i-1] + a[i]; // Accursively add a[i] to the running total
        // Update the sum by adding the count of the current modulo value
        sum += b[d[i]%m];
        if (i >= n) // Remove the modulo value that is outside the current window
            b[d[i-n]%m]--;
        // Increment the count of the current modulo value
        b[d[i]%m]++;
    }
    cout<<sum;
    return 0;
}