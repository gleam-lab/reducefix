#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    while (Q--) {
        ll b_j;
        int k_j;
        cin >> b_j >> k_j;

        // Using binary search to find the k_j-th closest element
        // The idea is to find the smallest distance d such that there are at least k_j elements in a within distance d of b_j
        ll left = 0;
        ll right = 2e14; // A sufficiently large upper bound for the distance

        while (left < right) {
            ll mid = (left + right) / 2;

            // Count the number of elements in a that are within distance mid of b_j
            auto lower = lower_bound(a.begin(), a.end(), b_j - mid);
            auto upper = upper_bound(a.begin(), a.end(), b_j + mid);

            int count = upper - lower;

            if (count >= k_j) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << '\n';
    }

    return 0;
}