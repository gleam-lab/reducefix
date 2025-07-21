#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define int long long

int find_kth_distance(const vector<int>& a, int b, int k) {
    int n = a.size();
    int left = 0;
    int right = 1e8 * 2;  // Maximum possible distance

    while (left < right) {
        int mid = (left + right) / 2;
        int count = 0;

        // Count numbers <= mid distance from b
        auto it_low = lower_bound(a.begin(), a.end(), b - mid);
        auto it_high = upper_bound(a.begin(), a.end(), b + mid);
        count = it_high - it_low;

        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;
        int distance = find_kth_distance(a, b, k);
        cout << distance << '\n';
    }
    
    return 0;
}