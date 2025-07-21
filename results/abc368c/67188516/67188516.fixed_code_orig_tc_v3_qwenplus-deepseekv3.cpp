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

    long long low = 0;
    long long high = 1e18; // A sufficiently large upper bound
    long long answer = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        vector<long long> temp = H;
        bool possible = true;

        for (int i = 0; i < N; ++i) {
            if (i < N - 1) {
                long long t3 = min(temp[i] / 3, mid / 3);
                temp[i] -= t3 * 3;
                temp[i+1] -= t3 * 1;
                temp[i] -= (mid - 3 * t3);
                if (temp[i] > 0) {
                    possible = false;
                    break;
                }
                if (temp[i+1] < 0) {
                    temp[i+1] = 0;
                }
            } else {
                long long t3 = min(temp[i] / 3, mid / 3);
                temp[i] -= t3 * 3;
                temp[i] -= (mid - 3 * t3);
                if (temp[i] > 0) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}