#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> sorted_a(n);
    for (int i = 0; i < n; ++i) {
        sorted_a[i] = {a[i], i};
    }

    sort(sorted_a.begin(), sorted_a.end());

    vector<int> ans(q);
    for (int qi = 0; qi < q; ++qi) {
        int b, k;
        cin >> b >> k;

        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int dist = abs(sorted_a[mid].first - b);
            if (dist == sorted_a[k - 1].first) {
                ans[qi] = dist;
                break;
            } else if (dist < sorted_a[k - 1].first) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}