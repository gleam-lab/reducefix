#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }
    
    sort(A.rbegin(), A.rend());
    
    int l = 0, r = N - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        int found = false;
        for (int i = 0; i < N - 1; i++) {
            if (mid < B[i]) {
                l = mid;
                break;
            } else if (mid >= A[i]) {
                found = true;
            }
        }
        if (!found) {
            r = mid - 1;
        }
    }
    
    if (A[l] > B[0]) {
        cout << A[l] << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}