#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    ll K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining + 1;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_vote = A[i] + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_vote) - sorted_A.begin();
            int candidates_above = N - pos;

            if (candidates_above < M) {
                best_X = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best_X != -1 && best_X <= remaining) {
            ans[i] = best_X;
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}