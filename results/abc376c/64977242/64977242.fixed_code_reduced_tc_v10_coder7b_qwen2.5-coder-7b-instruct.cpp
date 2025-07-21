#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N-1);

    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N - 1; ++i) cin >> B[i];

    // Sort both arrays to facilitate the pairing process
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if any toy is too big to fit in any box
    for(int i = 0; i < N - 1; ++i) {
        if(A[i] > B[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    // The largest toy must fit in the largest available box
    long long ans = A[N - 1];
    
    // Find the smallest box that can hold the largest toy
    for(int i = 0; i < N - 1; ++i) {
        if(B[i] >= ans) {
            ans = B[i];
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}