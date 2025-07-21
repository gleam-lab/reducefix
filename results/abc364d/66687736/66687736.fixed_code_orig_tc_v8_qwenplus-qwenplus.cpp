#include <bits/stdc++.h>
using namespace std;

#define ll long long

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

        // Find the index using binary search
        int pos = lower_bound(A.begin(), A.end(), b) - A.begin();

        int left = pos - 1;
        int right = pos;

        ll result = 0;

        // Two pointer approach to find the k-th smallest distance
        while (k--) {
            if (left < 0) {
                right++;
            } else if (right >= N) {
                left--;
            } else if (abs(A[left] - b) <= abs(A[right] - b)) {
                left--;
            } else {
                right++;
            }

            if (k == 0) {
                if (left < 0) {
                    result = abs(A[right - 1] - b);
                } else if (right >= N) {
                    result = abs(A[left + 1] - b);
                } else {
                    result = min(abs(A[left + 1] - b), abs(A[right - 1] - b));
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}