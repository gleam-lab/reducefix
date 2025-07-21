#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    for (int i = 0; i < N; ++i) {
        long long h = H[i];
        // Each enemy requires attacks until its health is reduced to 0 or less
        // We simulate the attack pattern: every 3rd second does 3 damage, others do 1
        // Find minimum T such that we can defeat this enemy

        long long t = 0;
        while (h > 0) {
            ++t;
            if (t % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
        T += t;
    }

    cout << T << endl;
    return 0;
}