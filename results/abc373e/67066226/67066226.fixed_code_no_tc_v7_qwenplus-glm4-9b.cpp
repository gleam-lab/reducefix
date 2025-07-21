#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct MinMaxResult {
    int min;  // Minimum votes needed to guarantee victory
    int max;  // Maximum votes that can be needed for victory
};

MinMaxResult getMinMaxVotes(int n, int m, long long k, const vector<long long>& a) {
    vector<long long> sortedA(a);
    sort(sortedA.begin(), sortedA.end(), greater<long long>());

    vector<long long> prefixSums(n + 1);
    prefixSums[0] = 0;
    for (int i = 0; i < n; ++i) {
        prefixSums[i + 1] = prefixSums[i] + sortedA[i];
    }

    long long requiredVotes = 0;
    long long votesNeeded = 0;
    for (int i = 0; i < m; ++i) {
        if (i < n) {
            votesNeeded += sortedA[i];
        } else {
            votesNeeded += (sortedA[0] * m) - (prefixSums[m] - prefixSums[0]);
        }
    }
    requiredVotes = votesNeeded;

    MinMaxResult result;
    result.min = result.max = votesNeeded;
    int topM = min(m, n);

    // Calculate minimum votes needed
    for (int i = 0; i < topM; ++i) {
        long long votesForTopM = prefixSums[i + 1] - prefixSums[0];
        if (votesForTopM > requiredVotes) {
            result.min = min(result.min, votesForTopM - requiredVotes);
        } else {
            break;
        }
    }

    // Calculate maximum votes needed
    long long votesExceeded = 0;
    for (int i = 0; i < n; ++i) {
        if (i < topM) {
            long long votesForTopM = prefixSums[topM] - prefixSums[0];
            votesExceeded += votesForTopM - (prefixSums[i + 1] - prefixSums[0]);
        } else {
            votesExceeded += (k + 1) - (prefixSums[i + 1] - prefixSums[0]);
        }
        if (votesExceeded > requiredVotes) {
            result.max = min(result.max, votesExceeded - requiredVotes);
        } else {
            break;
        }
    }

    return result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n);
    for (long long &ai : a) cin >> ai;

    vector<long long> sortedA(a);
    sort(sortedA.begin(), sortedA.end(), greater<long long>());

    vector<long long> prefixSums(n + 1);
    prefixSums[0] = 0;
    for (int i = 0; i < n; ++i) {
        prefixSums[i + 1] = prefixSums[i] + sortedA[i];
    }

    MinMaxResult result = getMinMaxVotes(n, m, k, a);

    for (int i = 0; i < n; ++i) {
        long long remainingVotes = k - (prefixSums[n] - prefixSums[0]);
        if (i < m) {
            cout << result.min << " ";
        } else {
            long long requiredVotes = prefixSums[m] - prefixSums[0] - (prefixSums[i + 1] - prefixSums[0]);
            if (remainingVotes >= requiredVotes) {
                cout << "0 ";
            } else {
                cout << -1 << " ";
            }
        }
    }

    return 0;
}