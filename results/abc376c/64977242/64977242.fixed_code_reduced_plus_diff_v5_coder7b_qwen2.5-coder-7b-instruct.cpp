#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFitAllToys(vector<int>& A, vector<int>& B, int maxSize) {
    int j = 0;
    for (int i = 0; i < A.size(); ++i) {
        while (j < B.size() && B[j] < A[i]) {
            ++j;
        }
        if (j >= B.size()) return false;
        ++j;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int left = 0, right = 1e9 + 10;
    int ans = -1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (mid == 0) {
            left = mid + 1;
            continue;
        }
        
        if (canFitAllToys(A, B, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}