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
        ll b;
        int k;
        cin >> b >> k;
        int l = 0, r = N - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (A[mid] >= b) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        int pos = l;
        vector<ll> distances;
        int left = max(0, pos - k);
        int right = min(N - 1, pos + k);
        for (int i = left; i <= right; ++i) {
            distances.push_back(abs(A[i] - b));
        }
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << '\n';
    }
    return 0;
}