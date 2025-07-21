#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200050;
int n, x[MAXN], p_prefix[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p_prefix[i];
        p_prefix[i] += p_prefix[i - 1];
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        // Binary search for the first position >= l
        int left_low = 1, right_low = n;
        while (left_low < right_low) {
            int mid = (left_low + right_low) / 2;
            if (x[mid] >= l) right_low = mid;
            else left_low = mid + 1;
        }
        int start_idx = left_low;

        // Binary search for the last position <= r
        int left_high = 1, right_high = n;
        while (left_high < right_high) {
            int mid = (left_high + right_high + 1) / 2;
            if (x[mid] <= r) left_high = mid;
            else right_high = mid - 1;
        }
        int end_idx = left_high;

        if (start_idx > end_idx || x[start_idx] < l || x[end_idx] > r) {
            cout << 0 << '\n';
        } else {
            cout << p_prefix[end_idx] - p_prefix[start_idx - 1] << '\n';
        }
    }

    return 0;
}