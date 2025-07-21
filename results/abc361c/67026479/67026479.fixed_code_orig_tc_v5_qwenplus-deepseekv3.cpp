#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // We need to choose N-K elements in original order to minimize max - min
    // The optimal solution is to find a segment in the sorted array where the elements can be picked in original order
    // So, we sort the array, and for each window of size N-K, check if those elements appear in order in the original array
    // Then, the answer is the minimal difference (sorted[i+N-K-1] - sorted[i]) among all such feasible windows

    // However, the above is not straightforward to implement due to the order constraint
    // An alternative approach is to realize that the optimal solution is to choose some window in the original array where the elements are as close as possible when sorted
    // But this is not directly applicable either

    // Another idea: the minimal possible difference is the difference between some N-K elements in the sorted array
    // So, the answer is the minimal sorted[i+N-K-1] - sorted[i] for all i where i+N-K-1 < N
    // This is because we can always pick the elements in the window [i, i+N-K-1] in the sorted array and remove the others

    // But wait, this doesn't consider the original order constraint. For example, what if the elements in the window are not in order in the original array?

    // So, this suggests that the initial approach of the code is incorrect, and we need a different method

    // The correct approach is to realize that in the optimal solution, the minimal max-min is achieved by choosing a window of N-K elements in the sorted array, but the original order constraint must be satisfied
    // However, checking all possible such windows is computationally expensive for large N

    // Therefore, the correct answer is to sort the array and then find the minimal difference between any N-K consecutive elements in the sorted array, because there must be at least one window where the elements can be selected in the original order while respecting the window's max and min

    sort(A.begin(), A.end());
    int m = N - K;
    int min_diff = INT_MAX;
    for (int i = 0; i + m <= N; ++i) {
        min_diff = min(min_diff, A[i + m - 1] - A[i]);
    }
    cout << min_diff << endl;

    return 0;
}