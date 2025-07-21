#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N-1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> possible_x;

    // Check if we can place all but one toy in the existing boxes
    bool possible = true;
    for (int i = 0; i < N-1; i++) {
        if (A[i] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A.back());
    }

    // Check another scenario: place the largest toy in the new box
    possible = true;
    for (int i = 0; i < N-1; i++) {
        if (A[i+1] > B[i]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A[0]);
    }

    // Check if any of the scenarios is possible
    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        // Find the minimum x among possible scenarios
        long long min_x = *min_element(possible_x.begin(), possible_x.end());
        cout << min_x << endl;
    }

    return 0;
}