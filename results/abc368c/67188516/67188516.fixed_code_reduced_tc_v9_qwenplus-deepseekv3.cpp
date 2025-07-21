#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    long long pos = 0; // pos indicates the next attack's position in the cycle (0, 1, 2)
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        while (h > 0) {
            T++;
            if (pos == 2) {
                h -= 3;
            } else {
                h -= 1;
            }
            pos = (pos + 1) % 3;
        }
    }
    cout << T << endl;
    return 0;
}