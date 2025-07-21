#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        while (H[i] > 0) {
            if ((ans + 1) % 3 == 0) {
                H[i] -= 3;
            } else {
                --H[i];
            }
            ++ans;
        }
    }

    cout << ans << '\n';
    return 0;
}