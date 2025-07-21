#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define arr array<int,3>

const int N=2e5+10,INF=1e18;

int a[N],b[N];
PII sa[N];

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        for(int i=1;i<=n;i++)
            cin>>a[i];
        
        for(int i=1;i<=n;i++)
            cin>>b[i];
            
        for(int i=1;i<=n;i++)
            sa[i]={a[i],b[i]};
        
        sort(sa+1,sa+1+n);
        
        int res=INF,sum=0;
        priority_queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(q.size()<k)
            {
                sum+=sa[i].se;
                q.push(sa[i].se);
                if(q.size()==k)
                    res=min(res,sa[i].fi*sum);
            }
            else
            {
                if(sa[i].se<q.top())
                {
                    sum-=q.top();
                    q.pop();
                    sum+=sa[i].se;
                    q.push(sa[i].se);
                    res=min(res,sa[i].fi*sum);
                }
            }
        }
        
        cout<<res<<endl;
    }
    return 0;
}