#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        int left = 0, right = N - 1;
        vector<ll> distances(N);
        for (int i = 0; i < N; ++i) {
            distances[i] = abs(A[i] - b);
        }
        int low = 0, high = 2e8;
        ll result = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll cnt = upper_bound(A.begin(), A.end(), b + mid) - lower_bound(A.begin(), A.end(), b - mid);
            if (cnt >= k) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << result << "\n";
    }
    return 0;
}