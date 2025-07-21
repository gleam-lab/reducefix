#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> A, B, maxBox;

int main() {
    cin >> N;
    A.resize(N);
    B.resize(N-1);
    maxBox.resize(N-1);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    // Find the maximum size of the existing boxes
    maxBox[0] = B[0];
    for (int i = 1; i < N - 1; i++) {
        maxBox[i] = max(B[i], maxBox[i-1]);
    }

    // Check if any toy cannot fit in any of the existing boxes
    for (int i = 0; i < N; i++) {
        bool canFit = false;
        for (int j = 0; j < N-1; j++) {
            if (A[i] <= maxBox[j]) {
                canFit = true;
                break;
            }
        }
        if (!canFit) {
            cout << -1 << endl;
            return 0;
        }
    }

    // The minimum box size x is the maximum size of the existing boxes plus one
    cout << maxBox[N-2] + 1 << endl;

    return 0;
}