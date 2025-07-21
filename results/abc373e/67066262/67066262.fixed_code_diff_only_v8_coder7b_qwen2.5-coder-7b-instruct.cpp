#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<long long> b = a;
    sort(b.begin(), b.end());

    vector<long long> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = b[i] + prefix[i];
    }

    vector<long long> answer(n, -1);

    for (int i = 0; i < n; i++) {
        long long l = -1, r = k + 1;
        while (r - l > 1) {
            long long mid = (l + r) / 2;
            long long rid = upper_bound(b.begin(), b.end(), b[i] + mid) - b.begin();
            long long lid = max(0LL, n - m - (i >= n - m ? 1 : 0));
            long long count = 0;

            if (rid > lid) {
                count += (rid - lid) * (b[i] + mid + 1) - (prefix[rid] - prefix[lid]);
            }

            if (lid <= i && i < rid) {
                count--;
            } else {
                count += mid;
            }

            if (count > k) {
                r = mid;
            } else {
                l = mid;
            }
        }

        if (l != k) {
            answer[order[i]] = l;
        }
    }

    for (auto i : answer) cout << i << ' ';
    return 0;
}