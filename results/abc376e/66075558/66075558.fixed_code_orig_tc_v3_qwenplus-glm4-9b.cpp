#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define int long long
int n, k;
int t;
pair<int, int>a[200005];
priority_queue<int, vector<int>, greater<int>>h; // min-heap
int sum_b = 0;
long long ans = INT_MAX;
signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a + 1, a + n + 1);
        sum_b = 0;
        ans = INT_MAX;
        h.clear();
        for (int i = 1; i <= n; i++) {
            h.push(a[i].second);
            sum_b += a[i].second;
            if (h.size() >= k) {
                sum_b -= h.top();
                h.pop();
            }
            ans = min(ans, max(a[i].first, sum_b) * (a[i].second - (k - h.size()) * a[i].second));
        }
        cout << ans << endl;
    }
    return 0;
}