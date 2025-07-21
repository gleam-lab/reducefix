#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define int long long

const int N = 2e5 + 9;
const int inf = 1e18;

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
        
        vector<int> bb(n);
        for (int i = 0; i < n; i++) {
            bb[i] = b[a[i].second].first;
        }
        
        priority_queue<int> pq;
        int sum = 0;
        int res = inf;
        
        for (int i = 0; i < n; i++) {
            if (pq.size() < k - 1) {
                pq.push(bb[i]);
                sum += bb[i];
            } else {
                int current = a[i].first * (sum + bb[i]);
                if (current < res) {
                    res = current;
                }
                
                if (k > 1 && bb[i] < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(bb[i]);
                    sum += bb[i];
                }
            }
        }
        
        cout << res << '\n';
    }
    return 0;
}