#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
const int INF = 1e18;

int n, q;
vector<int> a;

// Check if at least k points are within distance d of b
bool check(int b, int k, int d) {
    int left = b - d;
    int right = b + d;
    int l = lower_bound(a.begin(), a.end(), left) - a.begin();
    int r = upper_bound(a.begin(), a.end(), right) - a.begin();
    return (r - l) >= k;
}

int find_kth_distance(int b, int k) {
    int low = 0;
    int high = 2e8; // max possible distance between two points
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(b, k, mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << find_kth_distance(b, k) << '\n';
    }

    return 0;
}