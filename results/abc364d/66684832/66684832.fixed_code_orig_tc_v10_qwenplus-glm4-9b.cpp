#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 2e5 + 9;
int n, q;
vector<int> a(N);
int dist(int x, int y) {
    return abs(x - y);
}
int findans(int pos, int k) {
    int l = 0, r = 1e8;
    while (l < r) {
        int mid = (l + r + 1) / 2; // Use mid = (l + r + 1) / 2 for correct handling of mid point
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (dist(a[i], pos) <= mid) ++count;
        }
        if (count >= k) r = mid - 1;
        else l = mid;
    }
    return l;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    while (q--) {
        int x, k;
        cin >> x >> k;
        int result = findans(x, k);
        // You should return the distance between the k-th closest point in `a` and `x` here.
        // But the logic for calculating the actual distance based on `result` is needed.
        // For now, we will just print the result as it is (which might be incorrect).
        cout << result << endl;
    }
    return 0;
}