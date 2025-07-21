#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].votes;
        A[i].index = i;
    }

    // Sort candidates by current votes
    sort(A.begin(), A.end(), compare);

    // Prefix sum array
    vector<ll> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i].votes;
    }

    // Result array
    vector<ll> result(N);

    for (int i = 0; i < N; ++i) {
        // Binary search for minimal X such that candidate i can win
        ll low = 0;
        ll high = K;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;

            // Where does candidate i land after adding mid votes?
            ll new_vote_count = A[i].votes + mid;

            // Find first candidate with votes > new_vote_count using upper_bound
            auto it = upper_bound(A.begin(), A.end(), Candidate{new_vote_count, -1}, [](const Candidate &a, const Candidate &b) {
                return a.votes < b.votes;
            });

            int pos = it - A.begin();

            // Ensure the position is adjusted based on original index
            int max_allowed = N - M;
            if (pos > max_allowed) {
                // Too many candidates above, cannot guarantee win
                low = mid + 1;
            } else {
                // Try to minimize X
                answer = mid;
                high = mid - 1;
            }
        }

        result[A[i].index] = (answer == -1 ? -1 : answer);
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i];
        if (i < N - 1) cout << " ";
    }
    cout << endl;

    return 0;
}