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

    // ord[i] = original index of the candidate with the i-th smallest number of current votes
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int x, int y) { return A[x] < A[y]; });

    vector<ll> sorted_A = A;
    sort(all(sorted_A));

    // prefix sum of sorted_A
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i)
        prefix[i + 1] = prefix[i] + sorted_A[i];

    vector<ll> res(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx]; // original index of current candidate
        ll a_i = A[i];

        ll low = 0, high = K + 1;
        while (low < high) {
            ll mid = (low + high) / 2;

            // Number of candidates that must be beaten: M
            // Binary search to find how many candidates have strictly more than a_i + mid
            ll target = a_i + mid + 1;

            // Find how many candidates have votes >= target using binary search
            int pos = lower_bound(all(sorted_A), target) - sorted_A.begin();

            // Total votes needed to make those (N - pos) candidates not beat us
            ll need = (N - pos) * (target) - (prefix[N] - prefix[pos]);

            // Check if we are among those who get boosted
            if (mid == 0) {
                if (pos <= i && i < N) {
                    // already good
                } else {
                    res[i] = 0;
                }
                continue;
            }

            if (need <= K - mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        if (low > K)
            res[i] = -1;
        else
            res[i] = low;
    }

    for (auto x : res)
        cout << x << ' ';
    cout << '\n';
}