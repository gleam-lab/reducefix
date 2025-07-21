#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }

        // Sort by A values, and use a vector to track the index of B values in the original array
        vector<pair<int, int>> sorted_arr(n + 1);
        for (int i = 1; i <= n; i++) {
            sorted_arr[i] = {arr[i].first, i};
        }
        sort(sorted_arr.begin() + 1, sorted_arr.end());

        // Calculate prefix sums of B values in the original order
        vector<int> prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + arr[sorted_arr[i].second].second;
        }

        int min_value = INT_MAX;
        // Iterate over possible maximum values of A
        for (int i = 1; i <= n; i++) {
            int max_A = sorted_arr[i].first;
            int total_B = prefix_sum[k - 1];
            // Binary search for the smallest subset sum of B that is >= total_B
            int low = 1, high = n;
            while (low < high) {
                int mid = (low + high + 1) / 2;
                if (prefix_sum[mid] >= total_B) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            // Calculate the potential minimum value for this configuration
            int current_value = max_A * prefix_sum[low - k + 1];
            min_value = min(min_value, current_value);
        }

        cout << min_value << "\n";
    }
    return 0;
}