#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& A, vector<int>& B, long long x) {
    vector<int> boxes(B);
    sort(boxes.begin(), boxes.end());

    for(int i = 0; i < A.size(); ++i) {
        auto it = lower_bound(boxes.begin(), boxes.end(), A[i]);
        if(it == boxes.end()) return false;
        boxes.erase(it);
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n-1);
    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < n-1; ++i) cin >> B[i];

    sort(A.begin(), A.end());

    long long low = 0, high = 1e9 + 1, mid, ans = -1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(canPlace(A, B, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}