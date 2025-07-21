#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        k--; // convert to 0-based index

        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] <= b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int pos = right; // A[pos] is the largest element <= b

        int l = pos, r = pos + 1;
        vector<ll> distances;
        while (distances.size() <= k && (l >= 0 || r < N)) {
            if (r >= N || (l >= 0 && abs(A[l] - b) <= abs(A[r] - b))) {
                distances.push_back(abs(A[l] - b));
                l--;
            } else {
                distances.push_back(abs(A[r] - b));
                r++;
            }
        }
        cout << distances[k] << '\n';
    }

    return 0;
}