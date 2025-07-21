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
        k--; // Convert to 0-based index for easier handling

        // Binary search to find the k-th closest element to b
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (A[mid] < b) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int pos = left;

        // Now, find the k-th closest element around 'pos'
        vector<ll> distances;
        int l = pos - 1, r = pos;
        for (int i = 0; i < N; ++i) {
            if (l >= 0 && (r >= N || abs(A[l] - b) <= abs(A[r] - b))) {
                distances.push_back(abs(A[l] - b));
                l--;
            } else if (r < N) {
                distances.push_back(abs(A[r] - b));
                r++;
            }
        }

        cout << distances[k] << '\n';
    }

    return 0;
}