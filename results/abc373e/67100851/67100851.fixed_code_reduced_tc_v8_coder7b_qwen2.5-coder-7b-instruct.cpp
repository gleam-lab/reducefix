#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int candidateIndex, int remainingVotes, int M) {
    int countAbove = 0;
    for (size_t i = 0; i < candidates.size(); ++i) {
        if (i == candidateIndex) continue;
        if (candidates[i].votes > candidates[candidateIndex].votes + remainingVotes) {
            countAbove++;
        }
        if (countAbove >= M) {
            return false;
        }
    }
    return true;
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

    // Sort candidates based on their vote counts
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });

    // Calculate the prefix sum of votes
    vector<long long> prefixSum(N + 1);
    for (int i = 1; i <= N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + candidates[i - 1].votes;
    }

    vector<int> results(N, -1);

    for (int i = 0; i < N; ++i) {
        if (canWin(candidates, i, K - prefixSum[N], M)) {
            results[i] = 0;
            continue;
        }

        int low = 0, high = K - prefixSum[N];
        while (low < high) {
            int mid = (low + high) / 2;
            if (canWin(candidates, i, K - prefixSum[N] - mid, M)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (canWin(candidates, i, K - prefixSum[N] - low, M)) {
            results[i] = low;
        }
    }

    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}