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
    vector<ll> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<ll>());
    ll threshold = (M <= N) ? sortedA[M - 1] : 0;

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        if (remaining < 0) {
            ans[i] = -1;
            continue;
        }
        ll low = 0, high = remaining;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVote = A[i] + mid;
            vector<ll> temp = sortedA;
            auto it = find(temp.begin(), temp.end(), A[i]);
            if (it != temp.end()) {
                *it = newVote;
            }
            sort(temp.begin(), temp.end(), greater<ll>());
            ll newThreshold = (M <= N) ? temp[M - 1] : 0;
            if (newVote >= newThreshold) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = (best != -1 && best <= remaining) ? best : -1;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}