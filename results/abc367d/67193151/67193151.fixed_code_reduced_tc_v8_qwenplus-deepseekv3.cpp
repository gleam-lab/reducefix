#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k;
long long sum,cnt,a[2*N],d[2*N];
map<int,int> b;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    
    b[0]=1;
    for(int i=1;i<2*n;i++)
    {
        d[i]=d[i-1]+a[i];
        if(i>=n)
        {
            int rem=(d[i-n]%m+m)%m;
            b[rem]--;
        }
        int rem=(d[i]%m+m)%m;
        sum+=b[rem];
        if(i<n)
        {
            b[rem]++;
        }
    }
    cout<<sum;
    return 0;
}