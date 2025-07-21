#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

struct Candidate {
    ll a;
    int idx;
};

bool compareA(const Candidate &x, const Candidate &y) {
    return x.a < y.a;
}

bool compareIdx(const Candidate &x, const Candidate &y) {
    return x.idx < y.idx;
}

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<Candidate> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a;
        A[i].idx = i;
    }

    vector<Candidate> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), compareA);

    vector<ll> prefixSum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedA[i].a;
    }

    ll totalUsed = prefixSum[N];
    ll remaining = K - totalUsed;

    vector<ll> res(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i].a;
        int pos = lower_bound(sortedA.begin(), sortedA.end(), Candidate{current, 0}, compareA) - sortedA.begin();
        if (pos < N - M + 1) {
            // Need to ensure that after adding X, at least M candidates have votes <= current + X
            // We need to find the minimal X such that current + X >= sortedA[N - M].a
            ll target = sortedA[N - M].a;
            if (remaining >= target - current) {
                // The remaining votes can cover the difference
                res[i] = max(target - current, 0LL);
            } else {
                // Not enough remaining votes even if we take all
                res[i] = -1;
            }
        } else {
            // Already in the top M, no additional votes needed
            res[i] = 0;
        }
    }

    // Now, handle the case where remaining votes can be distributed to push others up
    // We need to find for each candidate the minimal X such that:
    // A_i + X >= the (M-th) largest A_j + (remaining - X) possibly distributed to others
    // But the correct approach is to consider the worst case where other candidates get as many votes as possible to push i down
    // So, we need to binary search X such that:
    // A_i + X > the sum of votes of the top M-1 candidates other than i, plus remaining - X

    // Alternative approach: find the minimal X such that A_i + X > (sum of the top M-1 candidates) + max(0, remaining - X)
    // But this is complex; instead, we can think of the worst case where the remaining votes are given to the top M-1 candidates other than i

    // So, the minimal X is such that A_i + X > (sum of the top M-1 candidates other than i) + (remaining - X)
    // This simplifies to X > (sum_top_M_minus_1 + remaining - A_i) / 2

    // The correct minimal X is max(0, (sum_top_M_minus_1 + remaining - A_i + 1) / 2)

    // Let's implement this logic

    for (int i = 0; i < N; ++i) {
        ll current = A[i].a;
        vector<Candidate> temp = sortedA;
        temp.erase(lower_bound(temp.begin(), temp.end(), Candidate{current, 0}, compareA));

        if (temp.size() < M - 1) {
            // Less than M-1 other candidates, meaning i is already in top M
            res[i] = 0;
            continue;
        }

        ll sumTopMminus1 = 0;
        for (int j = temp.size() - (M - 1); j < temp.size(); ++j) {
            sumTopMminus1 += temp[j].a;
        }

        ll requiredX = (sumTopMminus1 + remaining - current + 1) / 2;
        if (requiredX <= 0) {
            res[i] = 0;
        } else if (requiredX <= remaining) {
            if (res[i] == -1 || requiredX < res[i]) {
                res[i] = requiredX;
            }
        } else {
            if (res[i] == -1) {
                res[i] = -1;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}