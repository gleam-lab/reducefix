#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define arr array<int,3>

const int N=2e5+10, INF=0x3f3f3f3f, mod=1e9+7;

int a[N], b[N];
PII sa[N];
priority_queue<int, vector<int>, greater<int>> pq;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        
        for(int i = 1; i <= n; ++i)
            cin >> b[i];
            
        for(int i = 1; i <= n; ++i)
            sa[i] = {a[i], b[i]};
        
        sort(sa + 1, sa + n + 1);

        // Initialize the priority queue with the sum of the smallest K elements of B
        for(int i = 1; i <= k; ++i)
            pq.push(sa[i].se);
        
        int sum = accumulate(pq.begin(), pq.end(), 0LL);
        int ans = INF;

        // Iterate through the sorted array and update the sum accordingly
        for(int i = k + 1; i <= n; ++i) {
            int na = sa[i].fi;
            int nb = sa[i].se;
            
            if(na * sum < ans)
                ans = na * sum;
            
            sum -= pq.top();
            pq.pop();
            pq.push(nb);
            sum += nb;
        }

        // Check the last window
        if(k == n)
            ans = min(ans, sa[n].fi * accumulate(pq.begin(), pq.end(), 0LL));
        
        cout << ans << endl;
    }

    return 0;
}