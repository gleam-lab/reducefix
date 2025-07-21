#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long

int find_kth_closest(const vector<int>& a, int b, int k) {
    int n = a.size();
    int left = 0, right = 1e18;
    int answer = 1e18;

    while (left <= right) {
        int mid = (left + right) / 2;
        int lower = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
        int upper = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
        int count = upper - lower;

        if (count >= k) {
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

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        int b, k;
        cin >> b >> k;
        int low = 0, high = 1e18;
        int ans = 1e18;
        while (low <= high) {
            int mid = (low + high) / 2;
            auto it_low = lower_bound(a.begin(), a.end(), b - mid);
            auto it_high = upper_bound(a.begin(), a.end(), b + mid);
            int count = it_high - it_low;
            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}