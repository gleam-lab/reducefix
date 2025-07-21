#include <bits/stdc++.h>
using namespace std;

vector<int> A, B;

void solve() {
    int n, q; cin >> n >> q;
    A.resize(n); B.resize(q);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < q; i++) {
        cin >> B[i].first >> B[i].second;
        B[i].first--; // Adjusting index to be zero-based
    }

    // Sort points A
    sort(A.begin(), A.end());

    // For each query, find the k_j-th closest point to B_j
    for(auto &b : B) {
        int k = b.second;
        int left = 0, right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if((A[mid] - b.first) * (A[mid] - b.first) < (A[left] - b.first) * (A[left] - b.first)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // Calculate the distance to the k_j-th closest point
        int distance = abs(A[left - 1] - b.first);
        cout << distance << endl;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}