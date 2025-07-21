#include<bits/stdc++.h>
using namespace std;
using LL = __int128;
typedef long long ll;
const int N = 1e6+7;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    
    // Pair a and b, then sort based on a
    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        pairs[i] = {a[i], b[i]};
    }
    sort(pairs.begin(), pairs.end());
    
    // Extract sorted a and corresponding b
    vector<int> sorted_a(n), sorted_b(n);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = pairs[i].first;
        sorted_b[i] = pairs[i].second;
    }
    
    // Compute prefix sums of sorted_b
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + sorted_b[i];
    }
    
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        auto left = lower_bound(sorted_a.begin(), sorted_a.end(), l);
        auto right = upper_bound(sorted_a.begin(), sorted_a.end(), r);
        int left_idx = left - sorted_a.begin();
        int right_idx = right - sorted_a.begin();
        cout << prefix[right_idx] - prefix[left_idx] << endl;
    }
    return 0;
}