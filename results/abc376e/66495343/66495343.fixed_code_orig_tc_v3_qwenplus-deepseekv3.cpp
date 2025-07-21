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
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i=0; i<n; i++)
            cin >> sa[i].fi;
        
        for(int i=0; i<n; i++)
            cin >> sa[i].se;
        
        sort(sa, sa+n);
        
        int res = INF;
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> q; // min-heap to keep smallest (k-1) elements
        
        for(int i=0; i<n; i++) {
            int current_a = sa[i].fi;
            int current_b = sa[i].se;
            
            if(q.size() < k-1) {
                sum += current_b;
                q.push(current_b);
            } else {
                if (k == 1) {
                    res = min(res, current_a * current_b);
                } else {
                    res = min(res, current_a * (sum + current_b));
                    if (!q.empty() && current_b > q.top()) {
                        sum -= q.top();
                        q.pop();
                        sum += current_b;
                        q.push(current_b);
                    }
                }
            }
        }
        
        cout << res << endl;
    }
    return 0;
}