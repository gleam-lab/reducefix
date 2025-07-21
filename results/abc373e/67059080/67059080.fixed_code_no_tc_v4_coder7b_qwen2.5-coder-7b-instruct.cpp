#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

struct Node {
    ll val;
    int idx;
};

// Function to calculate the minimum additional votes needed
ll min_additional_votes(vector<ll>& votes, int i, int M, ll remaining_votes) {
    ll total_votes_needed = 0;
    int count_greater = 0;

    // Count candidates with more votes than the current candidate
    for (int j = 0; j < votes.size(); ++j) {
        if (votes[j] > votes[i]) {
            total_votes_needed += votes[j] + 1;
            count_greater++;
        }
    }

    // Calculate the remaining votes needed to secure victory
    ll additional_votes = max(0LL, total_votes_needed - remaining_votes);

    // Check if we can secure victory with the calculated additional votes
    if (additional_votes <= remaining_votes && count_greater < M) {
        return additional_votes;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N >> M >> K;
    vector<ll> votes(N);

    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
    }

    // Sort the votes array
    sort(votes.rbegin(), votes.rend());

    vector<ll> result(N);

    // Calculate the minimum additional votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        result[i] = min_additional_votes(votes, i, M, K);
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}