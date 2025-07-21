#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> queries(Q);
    for(int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        --queries[i].second;  // Adjusting k to zero-based index
    }

    sort(A.begin(), A.end());

    for(auto& [b, k] : queries) {
        int left = 0, right = N - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(k > mid) {
                k -= mid + 1;
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        cout << abs(A[left] - b) << '\n';
    }

    return 0;
}