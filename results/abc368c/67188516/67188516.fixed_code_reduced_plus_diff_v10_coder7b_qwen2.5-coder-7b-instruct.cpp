#include <iostream>
#include <vector>

using namespace std;

long long solve(const vector<int>& H) {
    long long T = 0;
    int N = H.size();
    while (true) {
        bool changed = false;
        for (int i = 0; i < N; ++i) {
            if (H[i] > 0) {
                ++T;
                if (T % 3 == 0) {
                    H[i] -= 3;
                } else {
                    --H[i];
                }
                changed = true;
            }
        }
        if (!changed) break;
    }
    return T;
}

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    cout << solve(H) << endl;
    return 0;
}