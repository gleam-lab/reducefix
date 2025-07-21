#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(const vector<Candidate>& candidates, int m, long long totalVotes, int i, long long additionalVotes) {
    vector<int> rank(candidates.size());
    iota(rank.begin(), rank.end(), 0);
    sort(rank.begin(), rank.end(), [&](int a, int b) { return candidates[a].votes + additionalVotes > candidates[b].votes + additionalVotes; });
    
    int aboveMe = 0;
    for (int j = 0; j < candidates.size(); ++j) {
        if (rank[j] == i) break;
        if (candidates[rank[j]].votes + additionalVotes > candidates[i].votes) {
            ++aboveMe;
        }
    }
    return aboveMe < m;
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
    
    sort(candidates.begin(), candidates.end(), [](const Candidate& a, const Candidate& b) { return a.votes < b.votes; });
    
    vector<long long> results(n, -1);
    for (int i = 0; i < n; ++i) {
        if (canWin(candidates, m, k, i, 0)) {
            results[i] = 0;
            continue;
        }
        
        long long left = 0, right = k;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canWin(candidates, m, k, i, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        results[i] = left;
    }
    
    for (long long result : results) {
        cout << result << " ";
    }
    cout << endl;
    
    return 0;
}