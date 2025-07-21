#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    // When K is even, removing K/2 elements from both ends.
    if (K % 2 == 0) {
        int min_val = A[0];
        int max_val = A[N - 1];
        cout << max_val - min_val << endl;
    } else { // When K is odd, removing K/2 - 1 elements from one end and K/2 + 1 elements from the other end.
        int min_val = min({A[0], A[N - 1]});
        int max_val = max({A[N - 2], A[K / 2]});
        cout << max_val - min_val << endl;
    }

    return 0;
}