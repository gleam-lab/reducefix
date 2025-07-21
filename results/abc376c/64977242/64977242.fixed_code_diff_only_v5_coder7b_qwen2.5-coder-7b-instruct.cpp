#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> A, B;

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N-1);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // Check if we can place all toys without needing a new box
    bool canPlace = true;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] > B[i]) {
            canPlace = false;
            break;
        }
    }

    if (canPlace) {
        cout << -1 << endl;
        return 0;
    }

    // Find the smallest x such that we can place all toys
    int x = B[N-2] + 1;

    // Check if placing toys in boxes of size x works
    vector<int> usedBoxes(N-1, 0);
    for (int i = 0; i < N; i++) {
        int toySize = A[i];
        bool placed = false;
        for (int j = 0; j < N-1; j++) {
            if (!usedBoxes[j] && toySize <= B[j] + x) {
                usedBoxes[j] = 1;
                placed = true;
                break;
            }
        }
        if (!placed) {
            x++;
            i--; // Re-check this toy with the next x
        }
    }

    cout << x << endl;

    return 0;
}