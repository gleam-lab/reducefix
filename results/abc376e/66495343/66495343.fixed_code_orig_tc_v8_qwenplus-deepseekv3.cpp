#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10, INF=1e18;

int a[N], b[N];
PII sa[N];

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        for(int i=0;i<n;i++)
            cin>>a[i];
        
        for(int i=0;i<n;i++)
            cin>>b[i];
            
        for(int i=0;i<n;i++)
            sa[i]={a[i], b[i]};
        
        sort(sa, sa+n);
        
        int res=INF, sum=0;
        priority_queue<int, vector<int>, greater<int>> q; // min-heap to keep largest (k-1) elements
        
        for(int i=0;i<n;i++)
        {
            int na = sa[i].fi;
            int nb = sa[i].se;
            
            if(q.size() < k-1)
            {
                sum += nb;
                q.push(nb);
            }
            else
            {
                if(q.size() > 0 && nb > q.top())
                {
                    sum -= q.top();
                    q.pop();
                    sum += nb;
                    q.push(nb);
                }
                res = min(res, na * sum);
            }
        }
        
        // Handle the case where k=1 separately
        if(k == 1)
        {
            res = INF;
            for(int i=0;i<n;i++)
                res = min(res, sa[i].fi * sa[i].se);
        }
        
        cout<<res<<'\n';
    }

    return 0;
}