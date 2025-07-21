#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    while (Q--) {
        int b;
        int k;
        cin >> b >> k;

        // Binary search on answer: minimum distance d such that there are at least k points within [b-d, b+d]
        int low = 0, high = 2e8 + 10;
        while (low < high) {
            int mid = (low + high) / 2;
            int left = b - mid;
            int right = b + mid;

            auto l = lower_bound(A.begin(), A.end(), left);
            auto r = upper_bound(A.begin(), A.end(), right);

            int count = r - l;

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        cout << low << "\n";
    }

    return 0;
}