#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
};

bool compareByVotes(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

// Function to compute minimum additional votes needed for candidate at position i
ll computeMinVotes(int i, vector<Candidate> &sorted, ll K, int N, int M) {
    ll low = 0, high = K;
    ll res = -1;

    // Precompute prefix sums of the sorted votes
    vector<ll> prefix(N + 1, 0);
    for (int j = 0; j < N; ++j)
        prefix[j + 1] = prefix[j] + sorted[j].votes;

    while (low <= high) {
        ll mid = (low + high) / 2;

        // Candidate i gets mid extra votes
        ll new_vote_count = sorted[i].votes + mid;

        // We want to ensure that *at most* M-1 candidates have more than this
        // So we find how many candidates can be forced to have <= new_vote_count

        // Binary search to find first candidate with votes > new_vote_count
        int pos = upper_bound(sorted.begin(), sorted.end(), Candidate{new_vote_count, -1}, [](ll val, const Candidate &c) {
            return val < c.votes;
        }) - sorted.begin();

        // To guarantee win, candidate must be in top M after adding X votes
        // If i is already among those who have votes <= new_vote_count,
        // then it's included in pos. But we need to ensure total number of candidates
        // strictly greater than new_vote_count is < M, i.e., (N - pos) < M

        if ((N - pos) < M) {
            // This is valid, try smaller X
            res = mid;
            high = mid - 1;
        } else {
            // Not enough advantage yet
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    ll total_current_votes = 0;

    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
        total_current_votes += candidates[i].votes;
    }

    K -= total_current_votes; // Remaining unassigned votes

    // Sort by current votes to simulate competition
    vector<Candidate> sorted = candidates;
    sort(sorted.begin(), sorted.end(), compareByVotes);

    vector<ll> result(N, -1);

    for (int i = 0; i < N; ++i) {
        ll minVotes = computeMinVotes(i, sorted, K, N, M);
        result[sorted[i].index] = (minVotes == -1 ? -1 : minVotes);
    }

    for (int i = 0; i < N; ++i)
        cout << max(0LL, result[i]) << " ";
    cout << endl;

    return 0;
}