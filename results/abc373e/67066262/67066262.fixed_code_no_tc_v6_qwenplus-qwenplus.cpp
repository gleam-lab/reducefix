#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for (ll &a : A) {
        cin >> a;
        K -= a;
    }

    // ord[i] = original index of the candidate with i-th smallest current votes
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });

    // sorted list of current votes
    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    // prefix sums of sorted_A
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i];

    vector<ll> res(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx]; // original index of current candidate
        ll a_i = A[i];

        ll low = 0, high = K + 1;

        while (low < high) {
            ll mid = (low + high) / 2;

            // Candidate i gets mid more votes => total votes = a_i + mid
            // We need to find how many candidates can have strictly more than a_i + mid
            // Binary search to find first value in sorted_A > a_i + mid
            int pos = upper_bound(all(sorted_A), a_i + mid) - sorted_A.begin();

            // If we want candidate i to be elected,
            // then at most M-1 candidates should have more than him
            // So we must ensure that at least (N - M + 1) candidates <= a_i + mid

            // How many candidates are currently strictly less than or equal to a_i + mid?
            int count = N - pos;

            // If already >= M candidates have more votes than i, even with extra votes, it's not enough
            if (count < M) {
                low = mid + 1;
                continue;
            }

            // Need to raise the smallest (N - M + 1) candidates (excluding i) to at most a_i + mid
            // Find the number of candidates we need to cap
            int cap_start = 0;
            int cap_end = idx; // since ord is sorted by A[i], and we're iterating in order

            // The position of candidate i in the sorted_A array
            int my_pos = lower_bound(all(sorted_A), a_i) - sorted_A.begin();
            if (my_pos < N && sorted_A[my_pos] == a_i) {
                while (my_pos < N && sorted_A[my_pos] == a_i)
                    ++my_pos;
            }
            my_pos--;

            // Total number of candidates who could have more than i after getting X votes
            int num_more = N - (upper_bound(all(sorted_A), a_i + mid) - sorted_A.begin());

            if (num_more < M) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        // After binary search, check if low is valid
        if (low <= K) {
            res[i] = low;
        } else {
            res[i] = -1;
        }
    }

    for (ll x : res)
        cout << x << " ";
    cout << "\n";
}