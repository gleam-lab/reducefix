#include <iostream>
#include <algorithm>
#include <vector>
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

    vector<ll> res(N, -1);
    ll remaining = K;
    for (int i = 0; i < N; ++i) {
        remaining -= A[i];
    }

    for (int i = 0; i < N; ++i) {
        ll target = A[i];
        int pos = upper_bound(sorted_A.begin(), sorted_A.end(), target) - sorted_A.begin();

        if (pos <= N - M) {
            // The candidate is not in the top M initially, need to add votes
            ll low = 0, high = remaining;
            ll best = -1;
            while (low <= high) {
                ll mid = (low + high) / 2;
                ll new_val = target + mid;
                int new_pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_val) - sorted_A.begin();
                if (new_pos > N - M) {
                    best = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            if (best != -1) {
                res[i] = best;
            }
        } else {
            // The candidate is already in the top M, no need to add votes
            res[i] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}