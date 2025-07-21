#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> A, B;

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end(), greater<long long>()); // Descending order for toys
    long long maxToySize = A[0]; // The largest toy size

    // If the largest toy can fit in the largest box, we are done
    if (maxToySize <= *max_element(B.begin(), B.end())) {
        cout << maxToySize << endl;
        return 0;
    }

    // If not, we need to find the minimum box size that can fit the largest toy
    auto it = upper_bound(B.begin(), B.end(), maxToySize);
    if (it == B.end()) {
        // If no box can fit the largest toy, then the next smallest box can be the minimum x
        cout << maxToySize << endl;
    } else {
        // If there's a box that can fit the largest toy, the next smallest box can be the minimum x
        cout << *(it - 1) << endl;
    }

    return 0;
}