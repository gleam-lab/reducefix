#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, q;
int a[N];

int count_within_distance(int b, int d) {
    long long left = b - d;
    long long right = b + d;
    auto lower = lower_bound(a + 1, a + n + 1, left);
    auto upper = upper_bound(a + 1, a + n + 1, right);
    return distance(lower, upper);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    while (q--) {
        int b, k;
        cin >> b >> k;

        int low = 0, high = 2e8;
        int answer = 2e8;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = count_within_distance(b, mid);

            if (cnt >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}