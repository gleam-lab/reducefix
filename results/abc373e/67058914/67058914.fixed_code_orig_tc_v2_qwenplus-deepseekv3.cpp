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

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    ll total_used = prefix[N];
    ll remaining = K - total_used;

    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = remaining + current;
        ll best = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_current = current + mid;

            int pos = upper_bound(sortedA.begin(), sortedA.end(), new_current) - sortedA.begin();
            int cnt = N - pos;

            if (cnt < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (best != -1) {
            ll new_current = current + best;
            int pos = upper_bound(sortedA.begin(), sortedA.end(), new_current) - sortedA.begin();
            ll sum_above = prefix[N] - prefix[pos];
            ll needed = new_current * (N - pos) - sum_above;

            if (needed <= remaining) {
                res[i] = best;
            } else {
                res[i] = -1;
            }
        } else {
            res[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}