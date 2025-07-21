#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int minRange = A[N - 1] - A[0]; // Initial minimum range

    // Two pointers approach
    int left = 0, right = N - 1;
    while (left < right) {
        int range = A[right] - A[left];
        if (left + K <= right) {
            range = min(range, A[right - K] - A[left + K]);
            minRange = min(minRange, range);
        }
        left++;
        right--;
    }

    // Check for the case when K is odd and we can remove a single element from either end
    if (K % 2 == 1) {
        minRange = min(minRange, min(A[N - 1] - A[N - 2], A[1] - A[0]));
    }

    cout << minRange << endl;

    return 0;
}