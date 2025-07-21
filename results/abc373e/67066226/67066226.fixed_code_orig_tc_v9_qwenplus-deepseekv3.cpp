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
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    ll remaining = K - sum;
    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll total = A[i] + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), total, greater<ll>()) - sorted_A.begin();
            if (pos < M) {
                best = mid;
                high = mid - 1;
            } else {
                ll needed = 0;
                if (pos > 0) {
                    needed = prefix[pos] - pos * total;
                }
                if (needed <= remaining - mid) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        ans[i] = best;
    }
    for (int i = 0; i < N; ++i) {
        cout << (ans[i] == -1 ? -1 : max(0LL, ans[i])) << " ";
    }
    return 0;
}