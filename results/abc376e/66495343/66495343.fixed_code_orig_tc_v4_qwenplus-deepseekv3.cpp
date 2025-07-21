#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i=1; i<=n; i++)
            cin >> a[i];
        
        for(int i=1; i<=n; i++)
            cin >> b[i];
            
        for(int i=1; i<=n; i++)
            sa[i] = {a[i], b[i]};
        
        sort(sa+1, sa+1+n);
        
        int res = LLONG_MAX;
        int sum = 0;
        priority_queue<int> q; // max heap to store the smallest K-1 elements
        
        for(int i=1; i<=n; i++) {
            int current_b = sa[i].se;
            if(q.size() < k-1) {
                sum += current_b;
                q.push(current_b);
            } else {
                if(!q.empty() && current_b < q.top()) {
                    sum -= q.top();
                    q.pop();
                    sum += current_b;
                    q.push(current_b);
                }
            }
            
            if(i >= k) {
                int current_a = sa[i].fi;
                res = min(res, current_a * (sum + current_b));
            }
        }
        
        cout << res << endl;
    }

    return 0;
}