#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define int long long
const int N = 2e5 + 9;

int n, k;
vector<pair<int, int>> a, b;

int solve() {
    // Remove the smallest elements from A and B to ensure min max value
    auto remove_min = [](vector<pair<int, int>>& v) {
        sort(v.begin(), v.end());
        v.erase(v.begin());
    };

    remove_min(a);
    remove_min(b);

    // Initialize sums and max_a
    int sum_k = 0, sum_other = 0, max_a = a[0].first;

    for (int i = 0; i < b.size(); ++i) {
        if (i < k) {
            sum_k += b[i].first;
        } else {
            sum_other += b[i].first;
        }
    }

    int answer = max_a * sum_k; // Initial answer with the smallest max_a in the first k elements

    // Adjust to find the minimum possible value
    for (int i = 0; i < b.size() && i < k; ++i) {
        sum_k -= b[i].first;
        sum_other += b[i].first;
        answer = min(answer, max_a * sum_k);
        max_a = min(max_a, a[i].first); // Update max_a
    }

    // Check if excluding some elements from the remaining k elements can minimize the answer
    int min_diff = LLONG_MAX;
    int remaining_sum = 0;
    for (int i = k; i < b.size(); ++i) {
        remaining_sum += b[i].first;
        min_diff = min(min_diff, remaining_sum - sum_other);
    }
    answer = min(answer, (max_a * (sum_k - min_diff)));

    return answer;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> b[i].first;
            a[i].second = b[i].first; // Store both in the same vector
        }
        cout << solve() << endl;
    }
    return 0;
}