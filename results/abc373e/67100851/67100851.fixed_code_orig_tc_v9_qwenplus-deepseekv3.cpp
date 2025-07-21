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

    vector<int> indices(N);
    for (int i = 0; i < N; ++i) {
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    vector<ll> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = A[indices[i]];
    }

    vector<ll> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sortedA[i];
    }

    ll remaining_votes = K - prefix[N];
    vector<ll> res(N, -1);

    for (int i = 0; i < N; ++i) {
        int pos = lower_bound(sortedA.begin(), sortedA.end(), A[indices[i]] + 1) - sortedA.begin();
        int required_pos = N - M;
        if (pos > required_pos) {
            res[indices[i]] = 0;
            continue;
        }

        ll low = 0, high = remaining_votes, ans = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll new_val = A[indices[i]] + mid;
            int new_pos = upper_bound(sortedA.begin(), sortedA.end(), new_val) - sortedA.begin();
            if (new_pos > required_pos) {
                ll needed = (new_pos - required_pos) * new_val - (prefix[new_pos] - prefix[required_pos]);
                if (needed <= remaining_votes - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        res[indices[i]] = ans;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}