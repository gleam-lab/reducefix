#include <bits/stdc++.h>
using namespace std;

bool canStoreAll(vector<int>& A, vector<int>& B, int x) {
    vector<int> combined(A.size() + B.size());
    merge(A.begin(), A.end(), B.begin(), B.end(), combined.begin());
    return *max_element(combined.begin(), combined.end()) <= x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < n - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int low = 0, high = 1e9, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(canStoreAll(A, B, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}