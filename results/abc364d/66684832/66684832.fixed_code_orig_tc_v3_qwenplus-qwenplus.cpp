#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int n, q;
vector<int> a;

// Binary search for k-th smallest distance using lower_bound and upper_bound
int query(int b, int k) {
    int left = 0, right = 2e8 + 10; // max possible distance is 2e8
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int l = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
        int r = upper_bound(a.begin(), a.end(), b + mid) - a.begin();

        if (r - l >= k) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << query(b, k) << "\n";
    }

    return 0;
}