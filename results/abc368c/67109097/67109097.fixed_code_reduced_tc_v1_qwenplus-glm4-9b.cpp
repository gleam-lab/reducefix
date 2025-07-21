#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) cin >> H[i];

    long long T = 0;
    int i = 0;

    while (i < N) {
        long long a = H[i];
        if (a == 0) {
            i++;
            continue;
        }

        long long add = (a - 1) / 3;
        if ((a - 1) % 3 == 0) {
            add++;
        }

        T += add;
        H[i] -= add * 3;
        a -= add * 3;

        if (a > 0) {
            T += a;
            H[i] = 0;
        }

        i++;
    }

    cout << T << endl;
    return 0;
}