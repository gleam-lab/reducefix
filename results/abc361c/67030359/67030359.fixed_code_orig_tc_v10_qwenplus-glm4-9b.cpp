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

    // Sort the array to consider removing the smallest and largest elements
    sort(A.begin(), A.end());

    int left = 0, right = N - 1;
    // Move the left pointer to the right as we can remove elements to the left
    while (left < right && K > 0) {
        // Since we are sorting, we can remove the smallest and largest elements to reduce the range
        // We prefer to remove the largest elements first because they have a greater impact on the range
        if (A[right] - A[left] < A[right - 1] - A[left - 1]) {
            right--;
            K--;
        } else {
            left++;
            if (left < right) {
                K--;
            }
        }
    }

    int result = A[right] - A[left];
    cout << result << endl;
    return 0;
}