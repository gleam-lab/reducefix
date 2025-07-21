#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int i, long long x, int M, long long remainingVotes) {
    int above = 0;
    for (const auto& c : candidates) {
        if (c.votes + x > candidates[i].votes) {
            above++;
        }
    }
    return above <= M;
}

void binarySearch(vector<Candidate>& candidates, int i, long long& result, long long remainingVotes, int M) {
    long long low = 0, high = remainingVotes;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canWin(candidates, i, mid, M, remainingVotes)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
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

    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) {
        return a.votes < b.votes;
    });

    long long remainingVotes = K - accumulate(candidates.begin(), candidates.end(), 0LL, [](long long sum, const Candidate& c) { return sum + c.votes; });
    vector<long long> results(N, 0);

    for (int i = 0; i < N; ++i) {
        if (candidates[i].votes >= (K - remainingVotes) / (N - i)) {
            results[candidates[i].index] = 0;
        } else {
            binarySearch(candidates, i, results[candidates[i].index], remainingVotes, M);
        }
    }

    for (long long r : results) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}