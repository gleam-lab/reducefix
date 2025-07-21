#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int INF = 1e18;

int n, q;
vector<int> a;

// Returns true if there are at least k elements within [b - mid, b + mid]
bool check(int b, int mid, int k) {
    int left = b - mid;
    int right = b + mid;
    int l = lower_bound(a.begin(), a.end(), left) - a.begin();
    int r = upper_bound(a.begin(), a.end(), right) - a.begin();
    return (r - l) >= k;
}

// Binary search for the k-th smallest distance
int find_kth_distance(int b, int k) {
    int low = 0;
    int high = 2e8; // Max possible distance given input bounds
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(b, mid, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(b, k) << '\n';
    }

    return 0;
}