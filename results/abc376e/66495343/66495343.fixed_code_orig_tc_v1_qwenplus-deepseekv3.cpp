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
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        for (int i = 0; i < n; ++i) {
            cin >> sa[i].fi;
        }
        for (int i = 0; i < n; ++i) {
            cin >> sa[i].se;
        }
        
        sort(sa, sa + n);
        
        int res = LLONG_MAX;
        int sum = 0;
        priority_queue<int> pq;
        
        for (int i = 0; i < n; ++i) {
            int current_a = sa[i].fi;
            int current_b = sa[i].se;
            
            if (pq.size() < k - 1) {
                sum += current_b;
                pq.push(current_b);
            } else {
                res = min(res, current_a * (sum + current_b));
                if (!pq.empty() && current_b < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    sum += current_b;
                    pq.push(current_b);
                }
            }
        }
        
        if (k == 1) {
            res = LLONG_MAX;
            for (int i = 0; i < n; ++i) {
                res = min(res, sa[i].fi * sa[i].se);
            }
        }
        
        cout << res << '\n';
    }
    
    return 0;
}