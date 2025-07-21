#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 5;
int t, n, k, a[maxN], b[maxN];

// Comparator function to sort pairs based on A[i] first, then B[i]
bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    return p1.second > p2.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> ab(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Create pairs and sort them based on the custom comparator
        for (int i = 0; i < n; ++i) ab[i] = {a[i], b[i]};
        sort(ab.begin(), ab.end(), cmp);

        long long sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < k; ++i) {
            sum += ab[i].second;
            pq.push(-ab[i].second); // Using negative to simulate min-heap using max-heap
        }

        long long ans = sum * ab[k - 1].first;
        for (int i = k; i < n; ++i) {
            if (-pq.top() > ab[i].second) {
                sum += ab[i].second - pq.top();
                pq.pop();
                pq.push(-ab[i].second);
            }
            ans = min(ans, sum * ab[i].first);
        }

        cout << ans << "\n";
    }
    return 0;
}