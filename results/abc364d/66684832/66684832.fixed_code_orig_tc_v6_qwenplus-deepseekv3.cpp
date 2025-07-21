#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

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
        --k; // convert to 0-based index

        int left = 0, right = N - 1;
        ll res = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            // Compute the number of elements <= A[mid] in A
            int count = upper_bound(A.begin(), A.end(), A[mid]) - A.begin();
            if (count <= k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Now, find the k-th smallest distance
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - b);
        }
        sort(distances.begin(), distances.end());
        cout << distances[k] << '\n';
    }

    return 0;
}