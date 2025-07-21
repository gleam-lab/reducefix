#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int M, long long totalVotes, int candidateIndex, long long additionalVotes) {
    vector<long long> remainingVotes(candidates.size());
    copy(begin(candidates), end(candidates), begin(remainingVotes));
    
    // Remove the candidate we're trying to win for from the remaining votes
    remainingVotes[candidateIndex] -= additionalVotes + 1;
    
    // Sort the remaining candidates by their vote counts
    sort(begin(remainingVotes), end(remainingVotes));
    
    // Count how many candidates have more votes than the target candidate
    int count = 0;
    for (size_t i = 0; i < remainingVotes.size(); ++i) {
        if (remainingVotes[i] > additionalVotes + candidates[candidateIndex].votes) {
            ++count;
        } else {
            break;
        }
    }
    
    // Check if the count is less than M
    return count < M;
}

void solve() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
    }
    
    // Calculate the total number of votes received by all candidates
    long long totalVotes = accumulate(begin(candidates), end(candidates), 0LL);
    
    // Calculate the remaining votes to be counted
    K -= totalVotes;
    
    // Sort candidates by their vote counts
    sort(begin(candidates), end(candidates), [&](const Candidate& a, const Candidate& b) {
        return a.votes > b.votes;
    });
    
    vector<long long> result(N, -1);
    
    for (int i = 0; i < N; ++i) {
        if (canWin(candidates, M, totalVotes, i, 0)) {
            result[i] = 0;
        } else {
            long long left = 0, right = K;
            while (left <= right) {
                long long mid = (left + right) / 2;
                if (canWin(candidates, M, totalVotes, i, mid)) {
                    result[i] = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}