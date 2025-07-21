#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    long long T = 0;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        while (H[i] > 0) {
            if (T % 3 == 0) {
                if (H[i] >= 3) {
                    H[i] -= 3;
                } else {
                    H[i] = 0;
                    T++;
                }
            } else {
                H[i]--;
                T++;
            }
        }
    }

    cout << T << endl;
    return 0;
}