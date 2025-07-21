#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

int A[MAXN];

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> sorted_A(N);
    for (int i = 0; i < N; i++) {
        cin >> sorted_A[i];
    }
    sort(sorted_A.begin(), sorted_A.end());

    while (Q--) {
        int B, k;
        cin >> B >> k;
        int left = 0, right = N - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sorted_A[mid] - B >= k - 1) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        cout << abs(sorted_A[left] - B) << endl;
    }

    return 0;
}