#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    while (Q--) {
        ll B, k;
        cin >> B >> k;
        ll left = 0, right = 1e18;
        while (left < right) {
            ll mid = (left + right) / 2;
            // B から距離 mid 以内の点の数をカウント
            auto it1 = lower_bound(A.begin(), A.end(), B - mid);
            auto it2 = upper_bound(A.begin(), A.end(), B + mid);
            ll count = distance(it1, it2);
            if (count >= k) right = mid;
            else left = mid + 1;
        }
        cout << left << endl;
    }
    return 0;
}
