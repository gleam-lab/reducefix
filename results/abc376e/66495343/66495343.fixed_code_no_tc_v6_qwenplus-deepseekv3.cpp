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
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> sa[i].fi;
        }
        for (int i = 0; i < n; i++) {
            cin >> sa[i].se;
        }
        sort(sa, sa + n);
        
        int res = INF;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            int current_a = sa[i].fi;
            int current_b = sa[i].se;
            
            if (min_heap.size() < k - 1) {
                min_heap.push(current_b);
                sum += current_b;
            } else {
                if (!min_heap.empty() && current_b > min_heap.top()) {
                    sum -= min_heap.top();
                    min_heap.pop();
                    min_heap.push(current_b);
                    sum += current_b;
                }
            }
            
            if (min_heap.size() == k - 1) {
                res = min(res, current_a * (sum + current_b));
            }
        }
        cout << res << endl;
    }
    return 0;
}