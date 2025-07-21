#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int T = 1; // T must start from 1 for the loop to work correctly.
    for (int i = 0; i < N; ++i) {
        while (H[i] > 0) {
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            T++;
        }
    }

    cout << T << endl;
    return 0;
}