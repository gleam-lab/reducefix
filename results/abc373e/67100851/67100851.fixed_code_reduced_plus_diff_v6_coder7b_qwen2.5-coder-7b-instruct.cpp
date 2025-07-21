#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int i, long long x) {
    int m = candidates.size();
    vector<int> remainingVotes(m, 0);

    // Calculate remaining votes needed for each candidate
    for (int j = 0; j < m; ++j) {
        if (j == i) {
            remainingVotes[j] = max(0LL, candidates[j].votes + x - (m - 1));
        } else {
            remainingVotes[j] = max(0LL, candidates[j].votes - (m - 1));
        }
    }

    // Sort candidates based on remaining votes needed
    sort(remainingVotes.begin(), remainingVotes.end());

    // Check if candidate i can win
    for (int j = 0; j < m - 1; ++j) {
        if (remainingVotes[j] > remainingVotes[j + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }

    // Sort candidates based on votes
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });

    vector<long long> result(n, 0);

    for (int i = 0; i < n; ++i) {
        // Binary search to find the minimum x
        long long left = 0, right = k;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (canWin(candidates, i, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        result[i] = left;
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}