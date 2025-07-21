#include <iostream>
using namespace std;

int main() {
    long long N, T = 0;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < N; i++) {
        while (H[i] > 0) {
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i]--;
            }
            T++;
            if (H[i] < 0) {
                H[i] = 0;
            }
        }
    }
    cout << T << endl;
    return 0;
}