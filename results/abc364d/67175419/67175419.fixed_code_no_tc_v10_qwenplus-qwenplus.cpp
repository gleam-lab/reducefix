#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
vector<int> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (q--) {
        int b, k;
        cin >> b >> k;

        // Binary search on distance
        int left = 0, right = 2e8;
        int answer = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            // Find the number of elements in [b - mid, b + mid]
            int low = b - mid;
            int high = b + mid;
            int count = upper_bound(a.begin(), a.end(), high) - lower_bound(a.begin(), a.end(), low);
            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}