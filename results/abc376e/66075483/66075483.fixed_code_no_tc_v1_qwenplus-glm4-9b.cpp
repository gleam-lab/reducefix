#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> a(N), b(N);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
        }

        // Sort by the first element in descending order
        sort(a.rbegin(), a.rend());

        // Use a max-heap for the B values of the smallest k elements in A
        auto cmp = [&](const pair<int, int>& l, const pair<int, int>& r) {
            return l.first > r.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        long long ans = inf, sumB = 0;
        for (int i = 0; i < k; i++) {
            pq.push({b[a[i].second].first, a[i].second});
            sumB += b[a[i].second].first;
        }

        // Calculate the initial answer with the smallest k elements
        ans = sumB * a[k - 1].first;

        // Iterate over the rest of the elements
        for (int i = k; i < n; i++) {
            sumB -= b[pq.top().second];
            pq.pop();
            pq.push({b[a[i].second].first, a[i].second});
            sumB += b[a[i].second].first;

            ans = min(ans, sumB * a[i].first);
        }

        cout << ans << endl;
    }
    return 0;
}