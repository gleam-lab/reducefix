#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, long long additionalVotes, int M) {
    int n = candidates.size();
    vector<long long> sortedVotes(n);
    copy(candidates.begin(), candidates.end(), sortedVotes.begin());
    sort(sortedVotes.begin(), sortedVotes.end());

    long long totalVotes = 0;
    int count = 0;

    for (int i = n - 1; i >= 0; --i) {
        totalVotes += sortedVotes[i];
        if (totalVotes > sortedVotes[n - 1] + additionalVotes) {
            ++count;
        } else {
            break;
        }
    }

    return count <= M - 1;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    vector<long long> results(N, -1);

    // Sort candidates based on their current votes
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });

    // Calculate the maximum additional votes needed for the last M candidates
    long long maxAdditionalVotes = 0;
    for (int i = 0; i < M; ++i) {
        maxAdditionalVotes += candidates[N - 1 - i].votes;
    }

    // Binary search for the minimum additional votes needed for each candidate
    for (int i = 0; i < N; ++i) {
        long long low = 0, high = maxAdditionalVotes;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canWin(candidates, mid, M)) {
                results[candidates[i].index] = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}