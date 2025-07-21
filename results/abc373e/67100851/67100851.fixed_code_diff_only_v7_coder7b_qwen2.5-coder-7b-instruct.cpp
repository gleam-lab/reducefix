#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int index, long long additionalVotes, int M, long long remainingVotes) {
    vector<long long> voteCounts(candidates.size());
    voteCounts[index] += additionalVotes;
    
    // Calculate the current total votes for all candidates
    long long currentTotal = accumulate(voteCounts.begin(), voteCounts.end(), 0LL);
    
    // Sort the candidates based on their vote counts
    sort(voteCounts.begin(), voteCounts.end(), greater<>());
    
    // Check if the candidate can win
    int countMoreVotes = 0;
    for (size_t i = 1; i < voteCounts.size(); ++i) {
        if (voteCounts[i] > voteCounts[0]) {
            ++countMoreVotes;
        } else {
            break;
        }
    }
    
    // The candidate can win if the count of candidates with more votes than them is less than M
    return countMoreVotes < M;
}

vector<long long> minAdditionalVotes(int N, int M, long long K, const vector<long long>& initialVotes) {
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i] = {initialVotes[i], i};
    }
    
    vector<long long> minVotes(N, 0);
    for (int i = 0; i < N; ++i) {
        long long leftVotes = K - accumulate(initialVotes.begin(), initialVotes.end(), 0LL);
        
        // Binary search to find the minimum additional votes needed
        long long low = 0, high = leftVotes + 1;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (canWin(candidates, i, mid, M, leftVotes)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        if (low <= leftVotes) {
            minVotes[i] = low;
        } else {
            minVotes[i] = -1;
        }
    }
    
    return minVotes;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    vector<long long> initialVotes(N);
    for (int i = 0; i < N; ++i) {
        cin >> initialVotes[i];
    }
    
    vector<long long> result = minAdditionalVotes(N, M, K, initialVotes);
    
    for (long long votes : result) {
        cout << votes << " ";
    }
    cout << endl;
    
    return 0;
}