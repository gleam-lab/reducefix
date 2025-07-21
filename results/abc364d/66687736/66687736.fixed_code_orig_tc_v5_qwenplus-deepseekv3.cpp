#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
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
        int left = 0, right = N - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid + 1 >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - b);
        }
        nth_element(distances.begin(), distances.begin() + k - 1, distances.end());
        cout << distances[k - 1] << '\n';
    }

    return 0;
}