#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int idx;
};

bool compare(const Candidate& a, const Candidate& b) {
    return a.votes < b.votes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> result(N, -1);
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i] = {A[i], i};
    }

    sort(candidates.begin(), candidates.end(), compare);

    // prefix sum of sorted votes
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].votes;
    }

    // total remaining votes
    ll total_remaining = K - prefix_sum[N];

    // binary search for each candidate
    for (int i = 0; i < N; ++i) {
        int pos = i; // position in sorted list
        ll low = 0, high = total_remaining;
        bool possible = false;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = candidates[pos].votes + mid;

            // Find how many candidates have votes > target (excluding self)
            int left = pos;
            int right = upper_bound(candidates.begin(), candidates.end(), Candidate{target, -1}, [](const Candidate& a, const Candidate& b) {
                return a.votes < b.votes;
            }) - candidates.begin();

            int stronger = N - right;
            if (right <= pos) stronger--;

            if (stronger < M) {
                result[candidates[pos].idx] = mid;
                high = mid - 1;
                possible = true;
            } else {
                low = mid + 1;
            }
        }

        if (!possible) {
            result[candidates[pos].idx] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (result[i] == -1) {
            cout << -1 << " ";
        } else {
            cout << result[i] << " ";
        }
    }
    cout << endl;

    return 0;
}