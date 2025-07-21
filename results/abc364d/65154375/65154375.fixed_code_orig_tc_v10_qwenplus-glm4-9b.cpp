#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 5;
vector<int> A, sortedA;

int main() {
    int N, Q;
    cin >> N >> Q;
    A.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // Preprocess A to create sortedA
    sortedA.resize(N + 1);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = A[i];
    }
    sort(sortedA.begin(), sortedA.end());

    while (Q--) {
        int b, k;
        cin >> b >> k;
        int l = 0, r = 1e9; // Initialize r to a large value
        while (l < r) {
            int mid = (l + r) / 2;
            int leftCount = upper_bound(sortedA.begin(), sortedA.end(), b - mid) - sortedA.begin();
            int rightCount = lower_bound(sortedA.begin(), sortedA.end(), b + mid) - sortedA.begin() - leftCount;
            if (leftCount + rightCount >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << endl; // l and r will be equal at the end
    }

    return 0;
}