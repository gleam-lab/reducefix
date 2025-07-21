#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N-1);

    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N-1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Find the first index where A[i] > B[i]
    int idx = -1;
    for(int i = 0; i < N-1; ++i) {
        if(A[i] > B[i]) {
            idx = i;
            break;
        }
    }

    // If no such index found, we need to find the minimum x such that A[N-1] <= x
    if(idx == -1) {
        cout << A[N-1] << endl;
    } else {
        // The minimum x should be at least A[idx+1] because A[idx] > B[idx]
        cout << A[idx+1] << endl;
    }

    return 0;
}