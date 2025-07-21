#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long T = 0;
    long long H[N];

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        while (H[i] > 0) {
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
            T++;
        }
    }
    cout << T << endl;
    return 0;
}