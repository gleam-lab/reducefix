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
        K -= A[i];
    }

    // ord will store indices sorted by A[i]
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx]; // original index of current candidate
        ll a_i = A[i];

        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;

            // Current candidate's total votes if given 'mid' more votes
            ll target = a_i + mid;

            // Binary search for number of candidates that can have at most target votes
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), target) - sorted_A.begin();

            // We need to ensure that at most M-1 candidates can have strictly more than target
            // So we want the top M-1 candidates to be <= target

            // Find how many candidates are above target
            int above = N - pos;

            // If already at most M-1 candidates are above, no need for extra votes
            if (above <= M - 1) {
                high = mid;
                continue;
            }

            // Need to increase votes so that only M-1 candidates have more
            int need_above = above - (M - 1);
            int start_idx = N - need_above;

            // Total votes needed to bring those `need_above` candidates down to `target`
            ll required = (prefix[N] - prefix[start_idx]) - (target * need_above);

            if (required <= K && mid <= K)
                high = mid;
            else
                low = mid + 1;
        }

        if (low > K)
            result[i] = -1;
        else
            result[i] = low;
    }

    for (auto x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}