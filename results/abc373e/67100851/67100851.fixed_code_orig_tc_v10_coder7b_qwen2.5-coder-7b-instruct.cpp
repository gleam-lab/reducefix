#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int M, long long remainingVotes, int candidateIndex) {
    long long totalVotes = accumulate(candidates.begin(), candidates.end(), 0LL, [](long long sum, const Candidate& c) { return sum + c.votes; });
    long long needed = candidates[candidateIndex].votes + 1 + M * (candidates.size() - M);
    
    if (totalVotes >= remainingVotes) {
        return false;
    }
    
    long long remainingNeeded = needed - totalVotes;
    return remainingNeeded <= remainingVotes;
}

vector<long long> minAdditionalVotes(vector<int>& A, int M, long long K) {
    int N = A.size();
    vector<Candidate> candidates(N);
    for (int i = 0; i < N; ++i) {
        candidates[i] = {static_cast<long long>(A[i]), i};
    }
    
    sort(candidates.rbegin(), candidates.rend());
    
    vector<long long> result(N, -1);
    long long remainingVotes = K - accumulate(A.begin(), A.end(), 0LL);
    
    for (int i = 0; i < N; ++i) {
        if (canWin(candidates, M, remainingVotes, i)) {
            result[i] = 0;
        } else {
            long long left = 0, right = remainingVotes;
            while (left < right) {
                long long mid = left + (right - left) / 2;
                if (canWin(candidates, M, remainingVotes - mid, i)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            result[i] = left;
        }
    }
    
    return result;
}

int main() {
    int N, M;
    long long K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<long long> result = minAdditionalVotes(A, M, K);
    
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}