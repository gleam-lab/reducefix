#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++) cin >> v[i].f >> v[i].s;

        // Sort based on the ratio A[i] / B[i]
        sort(begin(v), end(v), [](const pair<int, int>& a, const pair<int, int>& b) {
            return (double)a.f / a.s < (double)b.f / b.s;
        });

        // Min-heap to keep track of the smallest element in the current subset
        priority_queue<int, vector<int>, greater<int>> pq;
        int total_sum = 0;
        
        for(int i=0; i<n; i++) {
            pq.push(v[i].s);
            total_sum += v[i].s;

            // If the heap size exceeds K, remove the smallest element
            if(pq.size() > k) {
                total_sum -= pq.top();
                pq.pop();
            }

            // Calculate the result for the current subset
            if(pq.size() == k) {
                int max_val = pq.top();
                int result = max_val * v[i].f;
                cout << result << '\n';
            }
        }
    }
    return 0;
}