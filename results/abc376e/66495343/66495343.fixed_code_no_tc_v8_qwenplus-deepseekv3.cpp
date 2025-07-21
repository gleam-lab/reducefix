#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10, INF=1e18;

PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i=1; i<=n; i++)
            cin >> sa[i].fi;
        
        for(int i=1; i<=n; i++)
            cin >> sa[i].se;
        
        sort(sa+1, sa+1+n);

        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        int res = INF;

        for(int i=1; i<=n; i++) {
            if(i <= k) {
                sum += sa[i].se;
                min_heap.push(sa[i].se);
                if(i == k) {
                    res = min(res, sa[i].fi * sum);
                }
                continue;
            }

            if(sa[i].se > min_heap.top()) {
                sum -= min_heap.top();
                min_heap.pop();
                sum += sa[i].se;
                min_heap.push(sa[i].se);
            }

            res = min(res, sa[i].fi * sum);
        }

        cout << res << endl;
    }
    return 0;
}