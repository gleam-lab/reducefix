#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200000 + 5;
long long votes[MAXN];

// Binary search function to determine the minimum votes needed
long long bs(long long l, long long r, long long a, int m, int n) {
    long long ok = l, ng = r;
    while (abs(ok - ng) > 1) {
        long long mid = ok + (ng - ok) / 2;
        long long u = upper_bound(votes, votes + n, a + mid) - votes;
        long long diff = n - u;
        if (diff >= m) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }
    sort(votes, votes + n);
    vector<long long> prefixSum(n);
    prefixSum[0] = votes[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + votes[i];
    }

    for (int i = 0; i < n; ++i) {
        if (votes[i] >= m - 1) {
            cout << 0 << " ";
            continue;
        }
        long long additionalVotes = bs(0, k - prefixSum[n - 1], votes[i], m, n);
        if (additionalVotes + votes[i] >= m - 1) {
            cout << additionalVotes << " ";
        } else {
            cout << -1 << " ";
        }
    }
    return 0;
}