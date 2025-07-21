#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> possible_x;
    // Check if we can assign N-1 toys to N-1 boxes and the remaining to x
    for (int i = 0; i < N; i++) {
        long long x;
        if (i == N - 1) {
            x = A.back();
        } else {
            if (A[i] > B[i]) {
                x = A[i];
            } else {
                continue;
            }
        }
        // Now check if all other toys can be placed in the boxes excluding x
        vector<long long> newB = B;
        newB.push_back(x);
        sort(newB.begin(), newB.end());
        bool possible = true;
        for (int j = 0; j < N; j++) {
            if (A[j] > newB[j]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            possible_x.push_back(x);
        }
    }

    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        cout << *min_element(possible_x.begin(), possible_x.end()) << endl;
    }

    return 0;
}