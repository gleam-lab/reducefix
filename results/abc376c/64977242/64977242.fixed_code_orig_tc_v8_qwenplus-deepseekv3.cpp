#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N - 1; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> matched(N - 1, false);
    int j = 0;
    bool possible = true;
    for (int i = 0; i < N - 1; ++i) {
        while (j < N && A[j] > B[i]) {
            ++j;
        }
        if (j >= N) {
            possible = false;
            break;
        }
        matched[i] = true;
        ++j;
    }

    if (possible) {
        // All toys can be matched to existing boxes
        cout << 1 << endl;
    } else {
        // Need to find the smallest x such that when added, all toys can be placed
        // The x should be the smallest A[i] that is not covered by any B[j]
        sort(A.begin(), A.end(), greater<long long>());
        sort(B.begin(), B.end(), greater<long long>());

        long long x = -1;
        for (int i = 0; i < N; ++i) {
            if (i < N - 1 && A[i] > B[i]) {
                x = A[i];
                break;
            }
        }
        if (x == -1) {
            x = A.back();
        }

        // Verify if x allows all toys to be placed
        vector<long long> newB = B;
        newB.push_back(x);
        sort(newB.begin(), newB.end());
        sort(A.begin(), A.end());

        bool canPlace = true;
        j = 0;
        for (int i = 0; i < N; ++i) {
            while (j < N && A[i] > newB[j]) {
                ++j;
            }
            if (j >= N) {
                canPlace = false;
                break;
            }
            ++j;
        }

        if (canPlace) {
            cout << x << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}