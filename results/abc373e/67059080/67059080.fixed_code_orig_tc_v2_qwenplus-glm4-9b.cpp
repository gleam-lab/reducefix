#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Candidate {
    int votes;
    int id;
};

bool compare(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; i++) {
        cin >> candidates[i].votes;
        candidates[i].id = i + 1;
    }

    sort(candidates.begin(), candidates.end(), compare);

    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        int currentVotes = candidates[i].votes;
        int leadingVotes = i >= M ? candidates[M - 1].votes : INT_MAX;
        if (currentVotes + K - i - M >= leadingVotes) {
            result[i] = 0;
            continue;
        }

        // Calculate the minimum votes needed to guarantee victory
        int votesNeeded = leadingVotes - currentVotes + 1;
        int leadingIndex = upper_bound(candidates.begin(), candidates.begin() + N, {leadingVotes + 1, 0}, compare) - candidates.begin();
        int remainingVotes = K - currentVotes;

        if (i + 1 < leadingIndex) {
            votesNeeded -= i + 1;
        } else if (i + 1 == leadingIndex) {
            votesNeeded -= i;
        }

        result[i] = votesNeeded > remainingVotes ? -1 : votesNeeded;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << (i < N - 1 ? " " : "\n");
    }

    return 0;
}