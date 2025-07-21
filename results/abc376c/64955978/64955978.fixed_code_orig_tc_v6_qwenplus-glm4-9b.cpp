#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N - 1);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    long long max_a = *max_element(A.begin(), A.end());
    long long max_b = *max_element(B.begin(), B.end());

    // If the largest toy size is less than or equal to the largest box size,
    // then the smallest box needed would be of the size of the largest toy.
    if (max_a <= max_b) {
        cout << max_a << endl;
    } else {
        // Otherwise, we need to find the smallest box that can hold the largest toy.
        // This would be the largest box size from the existing boxes.
        cout << max_b << endl;
    }

    return 0;
}