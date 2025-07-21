#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    sort(sortedA.begin(), sortedA.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }
    vector<ll> res(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        int idx = lower_bound(sortedA.begin(), sortedA.end(), current) - sortedA.begin();
        ll low = 0, high = K, ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = current + mid;
            int pos = upper_bound(sortedA.begin(), sortedA.end(), new_val) - sortedA.begin();
            int cnt = N - pos;
            if (cnt < M) {
                ll required = 0;
                if (pos > N - M) {
                    required = (N - M - (pos - (N - M))) * new_val - (prefix[N - M] - prefix[pos - (N - M)]);
                }
                if (required <= K - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        res[i] = ans;
    }
    for (int i = 0; i < N; ++i) {
        cout << res[i] << ' ';
    }
    return 0;
}