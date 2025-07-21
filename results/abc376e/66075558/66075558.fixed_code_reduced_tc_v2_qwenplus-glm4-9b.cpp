#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) p[i] = {A[i], B[i]};
    sort(p.begin(), p.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    
    int sum = 0, best = 0;
    for (int i = 0; i < n; ++i) {
        sum += p[i].second;
        if (i >= k - 1) {
            best = max(best, sum);
        }
        if (i >= k - 1) {
            sum -= p[i - k].second;
        }
    }
    
    // Calculate the maximum of A in the first k elements
    int maxA = 0;
    for (int i = 0; i < k; ++i) {
        maxA = max(maxA, A[i]);
    }
    
    return maxA * best;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}