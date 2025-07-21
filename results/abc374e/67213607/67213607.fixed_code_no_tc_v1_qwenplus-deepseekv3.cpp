#include<bits/stdc++.h>
using namespace std;
long long n,x,a[105],p[105],b[105],q[105],l,r,mid,ans,minn,sum;
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>p[i]>>b[i]>>q[i];
    l=0,r=2e18;
    while(l<=r)
    {
        mid=(l+r)/2;
        sum=0;
        bool valid=true;
        for(int i=1;i<=n;i++)
        {
            minn=LLONG_MAX;
            // First option: use a[i] first then b[i]
            for(int j=0;j<=min(mid/a[i],100000LL);j++)
            {
                long long remaining=mid-j*a[i];
                if(remaining<0) continue;
                long long k=remaining/b[i];
                if(remaining%b[i]) k++;
                minn=min(minn,j*p[i]+k*q[i]);
            }
            // Second option: use b[i] first then a[i]
            for(int j=0;j<=min(mid/b[i],100000LL);j++)
            {
                long long remaining=mid-j*b[i];
                if(remaining<0) continue;
                long long k=remaining/a[i];
                if(remaining%a[i]) k++;
                minn=min(minn,j*q[i]+k*p[i]);
            }
            if(minn==LLONG_MAX)
            {
                valid=false;
                break;
            }
            sum+=minn;
            if(sum>x)
            {
                valid=false;
                break;
            }
        }
        if(valid && sum<=x)
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