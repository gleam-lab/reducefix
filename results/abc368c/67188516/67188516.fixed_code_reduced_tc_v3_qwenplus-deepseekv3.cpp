#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(long long T, const vector<long long>& H) {
    long long cnt = 0;
    for (long long h : H) {
        long long t = (h * 2 + 2) / 3; // Initial guess, needs adjustment
        // Correct calculation: the number of 3-damage attacks (x) and 1-damage attacks (y)
        // x + y <= T, and 3x + y >= h, y = T - x
        // So 3x + (T - x) >= h => 2x + T >= h => x >= (h - T)/2
        // Also, x <= T and x >= 0
        long long x = max(0LL, (h - T + 1) / 2);
        x = min(x, T / 3);
        if (3 * x + (T - x) >= h && T - x >= 0) {
            cnt += x;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long left = 0;
    long long right = *max_element(H.begin(), H.end()) * 2; // Upper bound
    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (isPossible(mid, H)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}