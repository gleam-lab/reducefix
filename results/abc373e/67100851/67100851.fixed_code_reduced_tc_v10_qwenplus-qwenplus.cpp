#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int idx;
};

bool compareByVotes(const Candidate &a, const Candidate &b) {
    return a.votes < b.votes;
}

bool canGuaranteeVictory(int i, ll additional, const vector<Candidate> &sorted, const vector<ll> &prefixSum, ll remainingK, int N, int M) {
    ll totalCandidates = N;
    ll requiredMore = M - 1;

    // Binary search to find how many candidates have votes strictly greater than (sorted[i].votes + additional)
    ll left = 0, right = N;
    while (left < right) {
        ll mid = (left + right) / 2;
        if (sorted[mid].votes > sorted[i].votes + additional)
            left = mid + 1;
        else
            right = mid;
    }
    ll greaterCount = N - left;

    if (greaterCount < requiredMore)
        return true;

    // Need to raise candidate i to position such that at least M-1 are above
    ll needAbove = requiredMore;
    ll pos = N - needAbove;
    if (pos <= i)
        pos--;

    if (pos < 0)
        return false;

    ll minRequired = (sorted[i].votes + additional + 1);
    ll targetPos = (sorted[i].votes + additional + 1);

    ll neededVotes = (targetPos * (N - pos)) - (prefixSum[N] - prefixSum[pos]);
    if (neededVotes > remainingK - additional)
        return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<Candidate> candidates(N);
    ll totalGiven = 0;

    for (int i = 0; i < N; ++i) {
        cin >> candidates[i].votes;
        totalGiven += candidates[i].votes;
        candidates[i].idx = i;
    }

    K -= totalGiven;

    sort(candidates.begin(), candidates.end(), compareByVotes);

    vector<ll> prefixSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + candidates[i].votes;
    }

    vector<ll> result(N);

    for (int i = 0; i < N; ++i) {
        ll lo = 0, hi = K;
        ll ans = -1;

        while (lo <= hi) {
            ll mid = (lo + hi) / 2;

            // Check if with 'mid' additional votes, candidate i is guaranteed victory
            ll greaterCount = 0;
            ll left = 0, right = N;
            while (left < right) {
                ll m = (left + right) / 2;
                if (candidates[m].votes > candidates[i].votes + mid)
                    left = m + 1;
                else
                    right = m;
            }
            greaterCount = N - left;

            if (greaterCount < M - 1) {
                ans = mid;
                hi = mid - 1;
                continue;
            }

            ll needAbove = M - 1;
            ll pos = N - needAbove;
            if (pos <= i)
                pos--;

            if (pos < 0 || pos >= N) {
                ans = mid;
                hi = mid - 1;
                continue;
            }

            ll requiredVote = candidates[i].votes + mid + 1;
            ll requiredTotal = requiredVote * (N - pos);
            ll currentSum = prefixSum[N] - prefixSum[pos];
            ll needed = requiredTotal - currentSum;

            if (needed <= K - mid) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        result[candidates[i].idx] = (ans == -1) ? -1 : ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}