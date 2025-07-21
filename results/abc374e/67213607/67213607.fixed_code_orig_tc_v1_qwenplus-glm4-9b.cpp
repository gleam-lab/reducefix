#include<bits/stdc++.h>
using namespace std;
long long n,x,a[105],p[105],b[105],q[105],l,r,mid,ans,minn,sum;
const long long MOD = 210000000000000000;

int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>p[i]>>b[i]>>q[i];
    l=0;
    r=1000000005;
    while(l<=r)
    {
        mid=(l+r)/2;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            minn=MOD;
            for(int j=0;j<=b[i];j++)
            {
                long long diff = mid - j * a[i];
                if (diff <= 0)
                {
                    minn = min(minn, j * p[i]);
                }
                else
                {
                    minn = min(minn, j * p[i] + (diff / b[i]) * q[i]);
                }
            }
            for(int j=0;j<=a[i];j++)
            {
                long long diff = mid - j * b[i];
                if (diff <= 0)
                {
                    minn = min(minn, j * q[i]);
                }
                else
                {
                    minn = min(minn, j * q[i] + (diff / a[i]) * p[i]);
                }
            }
            sum += minn;
        }
        if(sum <= x)
        {
            ans=max(ans,mid);
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
}