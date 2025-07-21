#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 200005;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    vector<pair<int, int>> P(n);
    for (int i = 0; i < n; ++i) {
        P[i] = {a[i], b[i]};
    }
    
    sort(P.begin(), P.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second > p2.second; // Sort by b value descending when a values are equal
    });
    
    long long sum = 0, ans = LLONG_MAX;
    priority_queue<int, vector<int>, greater<int>> que;
    
    // Calculate initial sum and min product for the first window of size k
    for (int i = 0; i < k; ++i) {
        sum += P[i].second;
        que.push(P[i].second);
    }
    ans = min(ans, P[k-1].first * sum);
    
    // Slide the window over the rest of the array
    for (int i = k; i < n; ++i) {
        sum += P[i].second - que.top(); // Add new element, remove the oldest from sum
        que.pop();
        que.push(P[i].second);
        ans = min(ans, P[i].first * sum); // Update answer
    }
    
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}