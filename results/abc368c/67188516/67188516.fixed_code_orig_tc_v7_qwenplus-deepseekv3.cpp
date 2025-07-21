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
    long long pos = 0; // 0, 1, 2 indicating the position in the 3-turn cycle

    for (long long h : H) {
        long long full_cycles = h / 5;
        T += full_cycles * 3;
        long long remainder = h % 5;

        if (remainder == 0) continue;

        if (pos == 0) {
            T += 1;
            pos = 1;
        } else if (pos == 1) {
            if (remainder <= 1) {
                T += 1;
                pos = 2;
            } else {
                T += 2;
                pos = 0;
            }
        } else { // pos == 2
            if (remainder <= 3) {
                T += 1;
                pos = 0;
            } else {
                T += 2;
                pos = 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}