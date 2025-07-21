#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, int i, long long additionalVotes, long long totalRemainingVotes, int M) {
    int count = 0;
    for (int j = 0; j < candidates.size(); ++j) {
        if (candidates[j].index != i) {
            long long requiredVotes = candidates[j].votes + additionalVotes + 1;
            if (requiredVotes > candidates[i].votes) {
                ++count;
                if (count >= M) return false;
            }
        }
    }
    return true;
}

vector<long long> minAdditionalVotes(int N, int M, long long K, vector<long long>& A) {
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i] = {A[i], i};
    }
    
    sort(candidates.begin(), candidates.end());
    
    vector<long long> result(N, -1);
    long long remainingVotes = K - accumulate(A.begin(), A.end(), 0LL);
    
    for (int i = 0; i < N; ++i) {
        if (canWin(candidates, i, 0, remainingVotes, M)) {
            result[i] = 0;
            continue;
        }
        
        long long low = 0, high = remainingVotes;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canWin(candidates, i, mid, remainingVotes - mid, M)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        result[i] = low;
    }
    
    return result;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<long long> results = minAdditionalVotes(N, M, K, A);
    
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}