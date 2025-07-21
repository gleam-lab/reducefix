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

    vector<long long> possible_x;
    for (int i = 0; i < N; ++i) {
        vector<long long> tempB = B;
        tempB.push_back(A[i]);
        sort(tempB.begin(), tempB.end());
        bool possible = true;
        for (int j = 0; j < N; ++j) {
            if (A[j] > tempB[j]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            possible_x.push_back(A[i]);
        }
    }

    if (!possible_x.empty()) {
        sort(possible_x.begin(), possible_x.end());
        cout << possible_x[0] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}