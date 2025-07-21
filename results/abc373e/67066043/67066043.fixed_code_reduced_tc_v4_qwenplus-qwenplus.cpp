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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        K -= A[i];
    }

    // ord will store indices of candidates sorted by current votes
    vector<int> ord(N);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return A[i] < A[j]; });

    vector<ll> sortedA = A;
    sort(all(sortedA));

    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> result(N, -1);

    for (int idx = 0; idx < N; ++idx) {
        int i = ord[idx]; // original index
        ll low = 0, high = K + 1;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;

            // We want to find the number of candidates > i in terms of votes
            // that could potentially be above candidate i after adding X votes

            // Find how many candidates have votes strictly greater than total
            int pos = lower_bound(sortedA.begin(), sortedA.end(), total + 1) - sortedA.begin();
            int count = N - pos;

            // If the candidate is already at position pos, adjust
            if (A[i] >= total + 1) {
                count++;
            }

            // To guarantee election, less than M candidates should have more votes
            if (count < M) {
                ans = mid;
                high = mid - 1;
            } else {
                // Need more votes
                low = mid + 1;
            }
        }

        if (ans <= K) {
            result[i] = ans == -1 ? 0 : ans;
        } else {
            result[i] = -1;
        }
    }

    for (auto x : result) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}