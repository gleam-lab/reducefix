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
        ll b, k;
        cin >> b >> k;
        int left = 0;
        int right = N - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] < b) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int pos = right + 1;
        int low = max(0, pos - k);
        int high = min(N - 1, pos + k - 1);
        vector<ll> candidates;
        for (int i = low; i <= high; ++i) {
            candidates.push_back(abs(A[i] - b));
        }
        sort(candidates.begin(), candidates.end());
        cout << candidates[k - 1] << '\n';
    }

    return 0;
}