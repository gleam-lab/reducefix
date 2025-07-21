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

    // If M >= N, then everyone is elected
    if (M >= N) {
        cout << string(N, '0') << endl;
        return 0;
    }

    vector<int> idx(N);
    iota(idx.begin(), idx.end(), 0);

    // Sort by current votes
    sort(idx.begin(), idx.end(), [&](int a, int b) { return A[a] > A[b]; });

    vector<ll> result(N, -1);

    // For each candidate, determine the minimum number of additional votes needed to guarantee victory.
    for (int i = 0; i < N; ++i) {
        int pos = i; // position in sorted list
        ll my_votes = A[pos];

        // Determine how many candidates have strictly more votes than me
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            if (j == pos) continue;
            if (A[j] > my_votes) cnt++;
        }

        // If already more than or equal to M candidates have more votes, already not elected
        if (cnt >= M) {
            result[pos] = 0;
            continue;
        }

        // Need to get at least (M - cnt) more votes than me to ensure we are among top M
        ll need = M - cnt;

        // Try binary search on X: minimal number of additional votes needed
        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;

            // After adding mid votes to this candidate
            ll new_vote = A[pos] + mid;

            // Count how many other candidates can possibly have more than new_vote
            int count_more = 0;
            for (int j = 0; j < N; ++j) {
                if (j == pos) continue;
                if (A[j] > new_vote) {
                    count_more++;
                }
            }

            if (count_more >= M) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // Check feasibility
        ll required = low;
        if (required <= K) {
            result[pos] = required;
        } else {
            result[pos] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}