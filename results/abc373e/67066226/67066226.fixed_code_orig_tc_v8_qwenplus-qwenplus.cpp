#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> C(N);

    // If M >= N, then every candidate will be elected regardless of votes.
    if (M >= N) {
        cout << string(N, '0');
        return 0;
    }

    // Create a list of candidate indices sorted by current votes descending
    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return A[i] > A[j]; });

    // For each candidate, determine the minimum additional votes needed to guarantee victory
    for (int i = 0; i < N; ++i) {
        ll need = 0;
        int count = 0;

        // Candidate number and current votes
        int ci = i;
        ll ai = A[i];

        // Check how many candidates have more votes than this one
        for (int j = 0; j < N && count < M; ++j) {
            if (A[idx[j]] > ai) {
                ++count;
            } else {
                break;
            }
        }

        // If already in top M, no need for extra votes
        if (count < M) {
            C[ci] = 0;
            continue;
        }

        // Otherwise, binary search on minimal X
        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;
            ai = A[i] + mid;
            count = 0;

            // Count how many other candidates have strictly more than ai
            for (int j = 0; j < N && count < M; ++j) {
                if (idx[j] == i) continue;
                if (A[idx[j]] > ai) ++count;
            }

            if (count < M) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (low <= K) {
            C[i] = low;
        } else {
            C[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << C[i] << " ";
    }

    return 0;
}