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

    // ord[i] gives the index of the candidate with the i-th smallest current votes
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int x, int y) { return A[x] < A[y]; });

    vector<ll> sortedA = A;
    sort(all(sortedA));

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> res(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx]; // Original index of current candidate
        ll ai = A[i];

        ll low = 0, high = K;
        ll answer = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll target = ai + mid;

            // Binary search to find how many candidates have strictly more than target
            ll pos = lower_bound(sortedA.begin(), sortedA.end(), target + 1) - sortedA.begin();

            // We want at most M-1 candidates with more votes
            if (N - pos >= M) {
                // Need more votes
                low = mid + 1;
            } else {
                answer = mid;
                high = mid - 1;
            }
        }

        res[i] = (answer == -1 ? -1 : answer);
    }

    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}