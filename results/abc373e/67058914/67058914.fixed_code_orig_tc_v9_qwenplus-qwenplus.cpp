#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Candidate {
    ll votes;
    int index;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    vector<ll> sorted_votes(N);

    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
        sorted_votes[i] = candidates[i].votes;
    }

    sort(sorted_votes.begin(), sorted_votes.end());

    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + sorted_votes[i - 1];
    }

    ll total_current = prefix_sum[N];
    ll remaining = K - total_current;

    vector<ll> result(N);

    // Function to calculate how many other candidates can be made to exceed 'target'
    auto needed_votes = [&](ll target, int exclude_index) -> ll {
        int l = 0, r = N - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (sorted_votes[mid] < target)
                l = mid;
            else
                r = mid - 1;
        }
        int count = l + 1;
        if (count >= M) return -1; // already enough candidates are below

        ll total_needed = 0;
        ll over_threshold = N - count;

        // Distribute just enough to make 'over_threshold' candidates not exceed 'target'
        for (int i = N - 1; over_threshold > 0 && i > count; --i) {
            if (sorted_votes[i] > target) {
                total_needed += max(0LL, sorted_votes[i] - target + 1);
                over_threshold--;
            }
        }

        return total_needed;
    };

    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll cur = candidates[i].votes;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_score = cur + mid;
            ll required = needed_votes(new_score, i);
            if (required == -1 || required > remaining - mid) {
                low = mid + 1;
            } else {
                answer = mid;
                high = mid - 1;
            }
        }

        result[candidates[i].index] = (answer == -1 ? -1 : answer);
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << '\n';

    return 0;
}