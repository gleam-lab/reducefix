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
    ll total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }
    ll remaining = K - total;

    if (M == N) {
        for (int i = 0; i < N; ++i) {
            cout << "0 ";
        }
        cout << endl;
        return 0;
    }

    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    vector<ll> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVote = A[i] + mid;
            int pos = upper_bound(sortedA.begin(), sortedA.end(), newVote) - sortedA.begin();
            int needed = N - M;
            if (pos > needed) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = best;
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] != -1 && ans[i] <= remaining) {
            cout << ans[i] << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;

    return 0;
}