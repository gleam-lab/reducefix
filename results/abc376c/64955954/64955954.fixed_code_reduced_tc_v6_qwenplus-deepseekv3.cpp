#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Function to check if x is feasible
    auto isFeasible = [&](int x) {
        vector<int> boxes = B;
        boxes.push_back(x);
        sort(boxes.begin(), boxes.end());
        
        int toy_ptr = N - 1;
        int box_ptr = N - 1;
        while (toy_ptr >= 0 && box_ptr >= 0) {
            if (boxes[box_ptr] >= A[toy_ptr]) {
                --toy_ptr;
                --box_ptr;
            } else {
                --toy_ptr;
            }
        }
        return toy_ptr < 0;
    };
    
    int low = 1;
    int high = 1e9;
    int answer = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isFeasible(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}