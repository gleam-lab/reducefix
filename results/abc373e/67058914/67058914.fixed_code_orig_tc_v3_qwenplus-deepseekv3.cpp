#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    ll remaining = K - prefix[N];
    if (remaining < 0) {
        remaining = 0;
    }

    vector<ll> res(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), total) - sorted_A.begin();
            if (pos == N) {
                best = mid;
                high = mid - 1;
                continue;
            }
            int cnt = N - pos;
            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        res[i] = best;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    cout << endl;

    return 0;
}