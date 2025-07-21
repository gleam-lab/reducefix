#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<long long, long long> pl;

long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }

        // Sort arrays based on A[i] and B[i]
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Priority queue to keep track of current sums
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long totalSum = 0;

        // Push first K elements into the priority queue
        for (int i = 0; i < k; ++i) {
            pq.push(b[a[i].second].first);
            totalSum += b[a[i].second].first;
        }

        long long ans = INF;
        // Calculate initial answer
        ans = min(ans, (totalSum + b[a[k].second].first) * a[k].first);

        // Iterate through remaining elements
        for (int i = k; i < n; ++i) {
            totalSum += b[a[i].second].first - pq.top();
            pq.pop();
            pq.push(b[a[i].second].first);
            ans = min(ans, (totalSum + b[a[i].second].first) * a[i].first);
        }

        cout << ans << "\n";
    }

    return 0;
}