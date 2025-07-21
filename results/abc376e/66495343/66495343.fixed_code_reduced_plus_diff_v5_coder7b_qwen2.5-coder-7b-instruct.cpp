#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define arr array<int,3>

const int N=2e5+10,INF=0x3f3f3f3f,mod=1e9+7;

int a[N],b[N];
PII sa[N];
priority_queue<PII,vector<PII>,greater<PII>> pq;

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

        long long res=LLONG_MAX,sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=sa[i].se;
            pq.push({sa[i].se});
            if(pq.size() > k)
                sum -= pq.top(),pq.pop();

            if(i >= k)
                res = min(res,(long long)sa[i].fi * sum);
        }

        cout<<res<<endl;
    }

    return 0;
}