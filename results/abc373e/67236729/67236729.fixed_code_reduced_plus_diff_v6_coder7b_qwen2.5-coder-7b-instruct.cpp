#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    vector<long long> prefix_sum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_a[i];
    }

    vector<long long> result(n);
    for (int i = 0; i < n; ++i) {
        int needed_votes = -1;
        int lower_bound_index = upper_bound(sorted_a.begin(), sorted_a.end(), a[i] + 1) - sorted_a.begin();
        int higher_bound_index = lower_bound(sorted_a.begin(), sorted_a.end(), a[i] + m) - sorted_a.begin();

        if (lower_bound_index > 0) {
            needed_votes = max(needed_votes, sorted_a[lower_bound_index - 1] - a[i]);
        }

        if (higher_bound_index < n) {
            needed_votes = max(needed_votes, sorted_a[higher_bound_index] - a[i] - 1);
        }

        if (needed_votes == -1) {
            result[i] = 0;
        } else {
            long long total_votes_needed = needed_votes * (n - 1);
            long long current_votes = prefix_sum[n] - prefix_sum[i + 1];
            if (total_votes_needed > k - current_votes) {
                result[i] = total_votes_needed - (k - current_votes);
            } else {
                result[i] = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}