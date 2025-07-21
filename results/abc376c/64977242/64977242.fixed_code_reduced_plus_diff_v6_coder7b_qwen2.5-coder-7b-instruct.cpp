#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceToys(vector<int>& A, vector<int>& B, int x) {
    vector<int> combined;
    combined.insert(combined.end(), A.begin(), A.end());
    combined.insert(combined.end(), B.begin(), B.end());
    
    sort(combined.begin(), combined.end());
    
    for (int i = 0; i < combined.size(); ++i) {
        if (combined[i] > x) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N-1; ++i) {
        cin >> B[i];
    }
    
    // Sort sizes to make binary search easier
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    // Initialize binary search bounds
    int left = 0, right = 1e9 + 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (canPlaceToys(A, B, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    cout << left << endl;
    
    return 0;
}