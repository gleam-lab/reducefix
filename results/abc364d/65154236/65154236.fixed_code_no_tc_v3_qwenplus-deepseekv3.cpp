#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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
            if (A[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int pos = right;
        int l = pos, r = pos + 1;
        vector<ll> distances;
        for (int i = 0; i < k; ++i) {
            if (l >= 0 && (r >= N || abs(A[l] - b) <= abs(A[r] - b))) {
                distances.push_back(abs(A[l] - b));
                --l;
            } else {
                distances.push_back(abs(A[r] - b));
                ++r;
            }
        }
        cout << distances[k - 1] << '\n';
    }

    return 0;
}