#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        long long health = H[i];
        while (health > 0) {
            if (ans % 3 == 0) {
                health -= 3;
            } else {
                health -= 1;
            }
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}