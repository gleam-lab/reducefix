#include<bits/stdc++.h>
using namespace std;
int n,m,a[400005],t[1000005]={0},an=0,w[400005];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=m;
        a[i+n]=a[i];
    }
    w[0]=0;
    for(int i=1;i<=2*n;i++)
    {
        w[i]=(w[i-1]+a[i])%m;
        if(i>n)
        {
            t[w[i-n]]--;
        }
        if(i>=n)
        {
            an+=t[w[i]];
            if(w[i]==w[i-n]) an++;  // count the subarray from i-n+1 to i
        }
        t[w[i]]++;
    }
    cout<<an;
    return 0;
}