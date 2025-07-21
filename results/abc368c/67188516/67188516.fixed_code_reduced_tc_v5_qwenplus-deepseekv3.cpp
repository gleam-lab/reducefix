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
    int phase = 0; // 0, 1, 2
    for (long long health : H) {
        long long full_cycles = health / 5;
        T += full_cycles * 3;
        long long remainder = health % 5;
        if (remainder == 0) {
            continue;
        }
        if (phase == 0) {
            if (remainder <= 2) {
                T += remainder;
                phase = (phase + remainder) % 3;
            } else {
                T += 3;
                phase = 0;
            }
        } else if (phase == 1) {
            if (remainder == 1) {
                T += 1;
                phase = 2;
            } else if (remainder <= 3) {
                T += 2;
                phase = (phase + 2) % 3;
            } else {
                T += 3;
                phase = 1;
            }
        } else { // phase == 2
            if (remainder == 1) {
                T += 1;
                phase = 0;
            } else if (remainder == 2) {
                T += 2;
                phase = 1;
            } else if (remainder == 3) {
                T += 2;
                phase = 0;
            } else { // remainder == 4
                T += 3;
                phase = 2;
            }
        }
    }
    cout << T << endl;
    return 0;
}