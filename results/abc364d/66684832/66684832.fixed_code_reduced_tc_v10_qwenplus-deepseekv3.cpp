#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define int long long
#define endl '\n'

int n, q;
vector<int> a;

bool check(int pos, int dx, int k) {
    int ln = lower_bound(a.begin(), a.end(), pos - dx) - a.begin();
    int rn = upper_bound(a.begin(), a.end(), pos + dx) - a.begin();
    return (rn - ln) >= k;
}

int findans(int pos, int k) {
    int l = 0, r = 2e18;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(pos, mid, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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
        int x, k;
        cin >> x >> k;
        cout << findans(x, k) << endl;
    }

    return 0;
}