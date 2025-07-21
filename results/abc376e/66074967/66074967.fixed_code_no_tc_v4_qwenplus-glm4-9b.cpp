#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

int solve() {
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
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = LLONG_MAX;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += b[i].first;
        if (i >= k - 1) {
            // We need to consider the current prefix sum up to the K-th smallest A[i] value
            ans = min(ans, (sum + b[i + 1].first) * a[i - k + 1].first);
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}