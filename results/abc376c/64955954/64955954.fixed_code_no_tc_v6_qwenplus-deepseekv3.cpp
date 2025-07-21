#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Function to check if x is feasible
    auto isFeasible = [&](int x) {
        vector<int> boxes = B;
        boxes.push_back(x);
        sort(bboxes.begin(), boxes.end());
        
        for (int i = 0; i < N; ++i) {
            if (A[i] > boxes[i]) {
                return false;
            }
        }
        return true;
    };
    
    // The minimum x is at least the largest toy
    int low = A[N - 1];
    int high = 1e18;
    int ans = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isFeasible(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}