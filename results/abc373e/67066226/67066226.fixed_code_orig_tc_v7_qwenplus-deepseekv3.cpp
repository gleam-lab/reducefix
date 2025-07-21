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

    vector<ll> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<ll>());
    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }

    vector<ll> ans(N, -1);
    for (int i = 0; i < N; ++i) {
        ll current = A[i];
        ll low = 0, high = K;
        ll best_X = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_votes = current + mid;
            // Find the number of elements > new_votes in the original array (excluding A[i])
            // We need at most M-1 elements > new_votes
            int cnt = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<ll>()) - sorted_A.begin();
            if (sorted_A[cnt - 1] == new_votes) {
                // Adjust to count only elements strictly greater
                cnt = lower_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<ll>()) - sorted_A.begin();
            }
            if (cnt >= M) {
                low = mid + 1;
                continue;
            }
            // The top 'cnt' elements are > new_votes. We need to ensure no more than M-1.
            // So the (M-1)th element should be <= new_votes.
            // The sum of votes needed to make M elements > new_votes is:
            // sum_{j=0}^{M-1} max(0, (new_votes + 1 - sorted_A[j]))
            // But since sorted_A is in descending order, the first M elements are the largest.
            ll total = 0;
            if (M >= 1) {
                ll limit = min(M, N);
                for (int j = 0; j < limit; ++j) {
                    if (sorted_A[j] > new_votes) {
                        total += (sorted_A[j] - new_votes);
                    } else {
                        break;
                    }
                }
            }
            if (total <= K - mid) {
                high = mid - 1;
                best_X = mid;
            } else {
                low = mid + 1;
            }
        }
        ans[i] = best_X;
    }

    for (int i = 0; i < N; ++i) {
        if (ans[i] == -1) {
            cout << -1 << " ";
        } else {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    return 0;
}