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

    vector<ll> sortedA = A;
    sort(all(sortedA));
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = K + current;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVotes = current + mid;
            int pos = upper_bound(all(sortedA), newVotes) - sortedA.begin();
            if (pos >= N - M + 1) {
                ll required = 0;
                int start = N - M;
                if (start < 0) start = 0;
                if (sortedA[start] >= newVotes) {
                    required = 0;
                } else {
                    required = (newVotes * (start + 1)) - prefix[start + 1];
                }
                if (required <= K) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        ans[i] = best;
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            // Check if already elected
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (A[j] > A[i]) {
                    cnt++;
                }
            }
            if (cnt < M) {
                ans[i] = 0;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}