#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;
int n, m, t, ans, k;
int s, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<pair<int, int>> a(N), b(N), bb(N);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> bb[i].first;
            bb[i].second = i;
        }

        sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first < y.first;
        });
        sort(bb.begin(), bb.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first < y.first;
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long sumB = 0;
        ans = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            sumB += bb[a[i].second].first;
            pq.push({bb[a[i].second].second, bb[a[i].second].first});
            if (pq.size() > k) {
                sumB -= pq.top().second;
                pq.pop();
            }
            if (pq.size() == k) {
                ans = min(ans, (sumB + pq.top().second) * a[i].first);
            }
        }

        cout << ans << endl;
    }
    return 0;
}