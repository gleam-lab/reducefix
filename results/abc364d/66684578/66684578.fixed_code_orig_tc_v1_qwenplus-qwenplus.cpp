#include <bits/stdc++.h>
using namespace std;

#define int long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // Prefix sum array based on sorted values
    map<int, int> freq;
    for (int x : A) {
        freq[x]++;
    }

    // Convert map to prefix sum list: (position, cumulative_count)
    vector<pair<int, int>> prefix;
    int cum = 0;
    for (auto [x, cnt] : freq) {
        cum += cnt;
        prefix.emplace_back(x, cum);
    }

    auto count_in_range = [&](int b, int d) -> int {
        int left = b - d;
        int right = b + d;
        auto it_left = lower_bound(prefix.begin(), prefix.end(), make_pair(left, 0LL));
        if (it_left == prefix.begin()) {
            if (prefix.empty() || prefix[0].first > right) return 0;
        }
        int l_idx = (it_left == prefix.begin()) ? 0 : (it_left - 1)->second;
        auto it_right = upper_bound(prefix.begin(), prefix.end(), make_pair(right, numeric_limits<int>::max()));
        int r_idx = (it_right == prefix.begin()) ? 0 : (it_right - 1)->second;
        return r_idx - l_idx;
    };

    while (Q--) {
        int b, k;
        cin >> b >> k;

        int low = 0, high = 2e8;
        int answer = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (count_in_range(b, mid) >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}