#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second

const int N=2e5+10, INF=1e18;

int a[N], b[N];
PII sa[N];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        for(int i=0; i<n; i++)
            cin >> a[i];
        
        for(int i=0; i<n; i++)
            cin >> b[i];
            
        for(int i=0; i<n; i++)
            sa[i] = {a[i], b[i]};
        
        sort(sa, sa+n);
        
        int res = INF;
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> q; // Min-heap to keep the smallest K-1 elements
        
        for(int i=0; i<n; i++) {
            int current_a = sa[i].fi;
            int current_b = sa[i].se;
            
            if(q.size() < k-1) {
                sum += current_b;
                q.push(current_b);
            } else {
                if(k == 1) {
                    res = min(res, current_a * current_b);
                    continue;
                }
                if(q.top() < current_b) {
                    sum -= q.top();
                    q.pop();
                    sum += current_b;
                    q.push(current_b);
                }
                res = min(res, current_a * sum);
            }
        }
        
        cout << res << endl;
    }
    return 0;
}