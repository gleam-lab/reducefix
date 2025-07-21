#include<bits/stdc++.h>
using namespace std;
long long n,x,a[105],p[105],b[105],q[105],l,r,mid,ans,minn,sum;
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>p[i]>>b[i]>>q[i];
    l=0,r=2000000000000000000LL;
    while(l<=r)
    {
        mid=(l+r)/2;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            minn=LLONG_MAX;
            // Try all possible combinations of operations
            for(int j=0;j<=100;j++)
            {
                long long remaining = mid - j*a[i];
                if(remaining <= 0)
                {
                    minn = min(minn, j * p[i]);
                    continue;
                }
                long long k = (remaining + b[i] - 1) / b[i]; // ceiling division
                minn = min(minn, j * p[i] + k * q[i]);
            }
            for(int j=0;j<=100;j++)
            {
                long long remaining = mid - j*b[i];
                if(remaining <= 0)
                {
                    minn = min(minn, j * q[i]);
                    continue;
                }
                long long k = (remaining + a[i] - 1) / a[i]; // ceiling division
                minn = min(minn, j * q[i] + k * p[i]);
            }
            sum += minn;
            if(sum > x) break; // Early termination if sum exceeds x
        }
        if(sum <= x)
        {
            ans = mid;
            l = mid+1;
        }
        else
        {
            r = mid-1;
        }
    }
    cout<<ans;
    return 0;
}