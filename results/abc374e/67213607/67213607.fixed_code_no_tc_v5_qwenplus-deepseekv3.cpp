#include<bits/stdc++.h>
using namespace std;
long long n,x,a[105],p[105],b[105],q[105],l,r,mid,ans,minn,sum;
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>p[i]>>b[i]>>q[i];
    l=0,r=2e18; // Adjusted to a sufficiently large upper bound
    while(l<=r)
    {
        mid=(l+r)/2;
        sum=0;
        bool valid=true;
        for(int i=1;i<=n;i++)
        {
            minn=LLONG_MAX;
            long long max_j = mid / a[i] + 1;
            for(long long j=0;j<=max_j;j++)
            {
                long long remaining = mid - j * a[i];
                if(remaining <= 0)
                {
                    minn=min(minn,j*p[i]);
                    continue;
                }
                long long k = (remaining + b[i] - 1) / b[i]; // Ceiling division
                minn=min(minn,j*p[i]+k*q[i]);
            }
            sum+=minn;
            if(sum > x)
            {
                valid=false;
                break;
            }
        }
        if(valid)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
}