#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N - 1);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // Check if all toys can be placed in existing boxes
    bool allPlaced = true;
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) {
            allPlaced = false;
            break;
        }
    }

    // If all toys can be placed in existing boxes, no new box is needed
    if (allPlaced) {
        cout << 0 << endl;
        return 0;
    }

    // Otherwise, find the minimum x such that all toys can be placed
    int x = 0; // Start with the smallest possible box
    while (x < N) {
        bool canPlace = true;
        for (int i = 0; i < N; ++i) {
            if (A[i] > B[i] + x) {
                canPlace = false;
                break;
            }
        }
        if (canPlace) {
            cout << x << endl;
            return 0;
        }
        ++x;
    }

    // If no valid x is found, output -1
    cout << -1 << endl;
    return 0;
}