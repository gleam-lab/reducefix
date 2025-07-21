#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vi a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Sort the A coordinates for binary search usage
    sort(a.begin(), a.end());

    for (int q = 0; q < Q; ++q) {
        int b, k;
        cin >> b >> k;

        // Binary search to find smallest distance d such that there are at least k points within distance <= d from b
        int left = -1;
        int right = 2e8 + 5;  // Max possible distance is up to 2e8

        auto count_points_in_range = [&](int d) {
            int low = b - d;
            int high = b + d;
            // Use lower_bound and upper_bound to count number of elements in range [low, high]
            auto it_low = lower_bound(a.begin(), a.end(), low);
            auto it_high = upper_bound(a.begin(), a.end(), high);
            return it_high - it_low;
        };

        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (count_points_in_range(mid) < k) {
                left = mid;
            } else {
                right = mid;
            }
        }

        cout << right << "\n";
    }

    return 0;
}