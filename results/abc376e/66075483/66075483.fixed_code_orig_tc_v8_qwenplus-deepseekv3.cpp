#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long

const int N = 2e5 + 9;

pair<int, int> a[N], b[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }
        
        sort(a, a + n);
        vector<int> B(n);
        for (int i = 0; i < n; i++) {
            B[i] = b[a[i].second].first;
        }
        
        int ans = LLONG_MAX;
        
        if (k == 1) {
            for (int i = 0; i < n; i++) {
                ans = min(ans, a[i].first * B[i]);
            }
        } else {
            priority_queue<int> pq;
            int sum = 0;
            
            for (int i = 0; i < k-1; i++) {
                pq.push(B[i]);
                sum += B[i];
            }
            
            for (int i = k-1; i < n; i++) {
                if (pq.size() == k-1) {
                    ans = min(ans, a[i].first * (sum + B[i]));
                }
                
                if (!pq.empty() && B[i] < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    sum += B[i];
                    pq.push(B[i]);
                }
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}