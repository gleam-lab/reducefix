#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long binary_search(long long low, long long high, function<bool(long long)> check) {
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (check(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    long long n, m, K;
    cin >> n >> m >> K;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<long long> prefix_sum(n + 1);
    partial_sum(begin(a), end(a), begin(prefix_sum));

    vector<long long> result(n);
    for (int i = 0; i < n; ++i) {
        auto check = [&](long long x) {
            long long needed_votes = a[i] + x;
            long long remaining_votes = K - prefix_sum[n] + prefix_sum[i] + x;
            long long total_votes_if_wins = needed_votes + remaining_votes;
            long long other_candidates = n - 1;
            long long can_win = total_votes_if_wins * (other_candidates + 1) >= total_votes_if_wins * (other_candidates - m + 1);
            return can_win;
        };

        if (check(0))
            result[i] = 0;
        else
            result[i] = binary_search(0, K, check);
    }

    for (int i = 0; i < n; ++i)
        cout << result[i] << " \n"[i == n - 1];

    return 0;
}