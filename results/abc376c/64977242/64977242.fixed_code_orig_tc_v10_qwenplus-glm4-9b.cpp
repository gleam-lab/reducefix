#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Sort toy and box sizes
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Find the smallest box size that can fit the largest toy
    long long min_x = LLONG_MAX;
    long long maxToySize = A[N - 1];
    for (auto b : B) {
        if (maxToySize <= b) {
            min_x = min(min_x, b);
        }
    }
    
    // If no box can fit the largest toy, output -1
    if (min_x == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_x << endl;
    }
    
    return 0;
}