#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];
    
    // Sort both vectors in descending order
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    long long toys_placed = 0, last_box_size = 0;
    for (int i = 0; i < N - 1 && toys_placed < N; ++i) {
        while (toys_placed < N && A[toys_placed] <= B[i]) {
            toys_placed++;
        }
        last_box_size = B[i];
    }

    // Check if all toys are placed
    if (toys_placed < N) {
        cout << -1 << endl;
    } else {
        cout << last_box_size << endl;
    }

    return 0;
}