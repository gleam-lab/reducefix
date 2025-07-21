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
        ll low = 0, high = K;
        ll best = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll newVote = A[i] + mid;
            int pos = upper_bound(all(sortedA), newVote) - sortedA.begin();
            int larger = N - pos;
            if (larger < M) {
                best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (best != -1 && best <= K) {
            ans[i] = best;
        } else {
            ans[i] = -1;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}