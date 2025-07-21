#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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

    ll remaining_votes = K;
    for (int i = 0; i < N; ++i) {
        remaining_votes -= A[i];
    }

    vector<ll> res(N);
    for (int i = 0; i < N; ++i) {
        ll low = 0;
        ll high = remaining_votes;
        ll ans = -1;

        while (low <= high) {
            ll mid = (low + high) / 2;

            ll total = A[i] + mid;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), total) - sorted_A.begin();
            if (pos > N - M) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res[i] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}