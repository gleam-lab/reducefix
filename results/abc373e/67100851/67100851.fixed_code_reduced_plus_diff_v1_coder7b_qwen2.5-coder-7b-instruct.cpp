#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Candidate {
    long long votes;
    int index;
};

bool canWin(vector<Candidate>& candidates, vector<long long>& prefixSum, int n, int m, int x, int i) {
    int above = lower_bound(candidates.begin(), candidates.end(), Candidate{prefixSum[n] + x - prefixSum[i + 1], 0}) - candidates.begin();
    if (above >= n - m) return false;
    int requiredVotes = (n - m - above) * (candidates[i].votes + x + 1) - (prefixSum[n] + x - prefixSum[i + 1]);
    return requiredVotes <= (prefixSum[i] + x);
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<Candidate> candidates(n);
    vector<long long> prefixSum(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i;
        prefixSum[i + 1] = prefixSum[i] + candidates[i].votes;
    }

    sort(candidates.begin(), candidates.end());

    vector<long long> results(n, -1);

    for (int i = 0; i < n; ++i) {
        if (canWin(candidates, prefixSum, n, m, k - prefixSum[n], i)) {
            results[i] = 0;
        } else {
            int left = 0, right = k - prefixSum[n];
            while (left < right) {
                int mid = (left + right) / 2;
                if (canWin(candidates, prefixSum, n, m, k - prefixSum[n] - mid, i)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            results[i] = left;
        }
    }

    for (long long result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}