#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, vector<long long>& prefixSums, long long totalVotes, int M, int targetIndex) {
    int n = candidates.size();
    int needed = 0;
    for (int i = 0; i < n; ++i) {
        if (i == targetIndex) continue;
        if (candidates[i].votes + totalVotes > candidates[targetIndex].votes) {
            needed += candidates[i].votes + totalVotes - candidates[targetIndex].votes;
        }
    }
    int rank = upper_bound(candidates.begin(), candidates.end(), Candidate{prefixSums.back() - prefixSums[candidates[targetIndex].index], candidates[targetIndex].index}, [&](const Candidate& c, const Candidate& val) { return c.votes < val.votes; }) - candidates.begin();
    if (rank <= n - M - 1) {
        return true;
    }
    return needed <= totalVotes;
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
    sort(candidates.begin(), candidates.end());
    vector<long long> prefixSums(N + 1);
    partial_sum(candidates.begin(), candidates.end(), prefixSums.begin() + 1);
    
    vector<int> results(N, 0);
    for (int i = 0; i < N; ++i) {
        long long low = 0, high = K - prefixSums.back() + candidates[i].votes;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (canWin(candidates, prefixSums, mid, M, i)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        results[i] = canWin(candidates, prefixSums, low, M, i) ? low : -1;
    }
    
    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;
    return 0;
}