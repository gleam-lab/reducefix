#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K;
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<ll>());

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    ll total = prefix[N];
    ll remaining = K - total;

    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = remaining;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = current + mid;

            int pos = upper_bound(sortedA.begin(), sortedA.end(), new_val, greater<ll>()) - sortedA.begin();

            if (pos < M) {
                ans = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                if (pos > 0) {
                    needed = new_val * pos - prefix[pos];
                }

                if (needed <= remaining - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        res[i] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}