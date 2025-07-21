#include<bits/stdc++.h>
using namespace std;
int n,m,a[400005],t[1000005],an,w[400005];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=m;
        a[i+n]=a[i];  // Extend the array to handle wrap-around
    }
    for(int i=1;i<2*n;i++)
    {
        w[i+1]=(w[i]+a[i])%m;  // Compute the prefix sum modulo m
        if(i>=n)
        {
            t[w[i]]++;  // Increment the count of current prefix sum
        }
        if(i>n)
        {
            t[w[i-n]]--;  // Decrement the count of prefix sum from n steps ago
        }
        if(i>=n)
        {
            an+=t[w[i]];  // Add the count of current prefix sum to the answer
        }
    }
    cout<<an;
    return 0;
}