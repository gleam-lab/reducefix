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
    for (int i = 0; i < N; ++i) cin >> A[i];

    // We need to compute for each candidate how many additional votes are needed
    vector<ll> res(N, -1);

    // For each candidate, we will simulate the scenario where this candidate gets enough votes to be in top M
    for (int i = 0; i < N; ++i) {
        vector<ll> B = A; // copy of current votes

        // Binary search on number of additional votes X
        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;

            // Simulate giving mid extra votes to candidate i
            B[i] = A[i] + mid;

            // Sort other candidates' vote counts
            vector<ll> temp = A;
            temp[i] += mid;

            // Sort in descending order
            sort(temp.rbegin(), temp.rend());

            // Candidate i's votes is temp[i]
            // We need to find how many candidates have strictly more than temp[i]
            int rank = 0;
            for (int j = 0; j < N; ++j) {
                if (temp[j] > temp[i]) ++rank;
            }

            // If there are less than M candidates with more votes, then candidate i is elected
            if (rank < M) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // Check if solution exists within available remaining votes
        if (low <= K) {
            res[i] = low;
        } else {
            res[i] = -1;
        }
    }

    // Output result
    for (auto x : res) cout << x << ' ';
    cout << '\n';
}