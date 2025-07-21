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

    long long ans = 0;
    int pos = 0; // T % 3, initial T is 0, so pos is initially 0

    for (long long h : H) {
        long long full_cycles = h / 5;
        ans += full_cycles * 3;
        long long remainder = h % 5;

        if (remainder == 0) {
            continue;
        }

        if (pos == 0) {
            if (remainder <= 2) {
                ans += remainder;
                pos += remainder;
            } else {
                ans += 3;
                pos = 0;
            }
        } else if (pos == 1) {
            if (remainder == 1) {
                ans += 1;
                pos += 1;
            } else if (remainder <= 3) {
                ans += 2;
                pos = 0;
            } else {
                ans += 3;
                pos = 1;
            }
        } else if (pos == 2) {
            if (remainder == 1) {
                ans += 2;
                pos = 1;
            } else if (remainder == 2) {
                ans += 2;
                pos = 0;
            } else if (remainder == 3) {
                ans += 1;
                pos = 0;
            } else {
                ans += 3;
                pos = 2;
            }
        }
        pos %= 3;
    }

    cout << ans << endl;
    return 0;
}