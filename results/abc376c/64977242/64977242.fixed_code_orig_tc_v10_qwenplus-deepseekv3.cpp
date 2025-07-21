#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    vector<long long> B(N - 1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> possible_x;
    // Check if we can place all toys in existing boxes
    bool all_fit = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            all_fit = false;
            break;
        }
    }
    if (all_fit) {
        // The largest toy might need a new box
        possible_x.push_back(A.back());
    }

    // Another scenario: replace one B with a new x
    // We need to find the smallest x such that:
    // The largest toy is placed in x, and the rest fit in the remaining B's
    sort(A.begin(), A.end(), greater<long long>());
    sort(B.begin(), B.end(), greater<long long>());

    // The largest toy must be <= x, and the next N-1 largest toys must fit in the N-1 largest B's
    bool possible = true;
    for (int i = 1; i < N; i++) {
        if (A[i] > B[i - 1]) {
            possible = false;
            break;
        }
    }
    if (possible) {
        possible_x.push_back(A[0]);
    }

    if (possible_x.empty()) {
        cout << -1 << endl;
    } else {
        cout << *min_element(possible_x.begin(), possible_x.end()) << endl;
    }

    return 0;
}