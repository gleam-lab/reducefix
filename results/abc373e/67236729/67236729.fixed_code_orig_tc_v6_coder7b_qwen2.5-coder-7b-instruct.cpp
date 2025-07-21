#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    vector<int> prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    vector<int> results(n, 0);

    for (int i = 0; i < n; ++i) {
        int target = prefix_sum[i] + 1;
        int low = 0, high = k;
        while (low < high) {
            int mid = (low + high) / 2;
            int remaining_votes = k - mid;
            int votes_needed = prefix_sum[min(m - 1, i + 1)] - prefix_sum[i + 1];

            if (votes_needed <= remaining_votes) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        results[i] = low - a[i];
        if (results[i] < 0) results[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}