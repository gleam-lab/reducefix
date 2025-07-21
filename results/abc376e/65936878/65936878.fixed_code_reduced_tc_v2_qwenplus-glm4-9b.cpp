#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].f >> v[i].s;
        
        // Sort the vectors based on the negative of the first element to simulate a max heap
        sort(v.rbegin(), v.rend());

        long long sum = 0;
        priority_queue<int> pq;
        long long ans = LLONG_MAX;

        // Initialize the priority queue with the first 'k' elements' second parts
        for (int i = 0; i < k; i++) {
            sum += v[i].s;
            pq.push(v[i].s);
        }

        // For each subsequent element, we calculate the potential answer
        for (int i = k; i < n; i++) {
            ans = min(ans, (sum + pq.top()) * v[i].f);
            sum += v[i].s;
            pq.push(v[i].s);
            sum -= pq.top();
            pq.pop();
        }

        // Final check after the loop is done
        ans = min(ans, sum * v[k-1].f);

        cout << ans << '\n';
    }
    return 0;
}