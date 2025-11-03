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
    int pos = 0; // position in the cycle: 0,1,2 where 2 means next attack will be triple damage

    for (int i = 0; i < N; ++i) {
        while (H[i] > 0) {
            T++;
            pos = (pos + 1) % 3;
            
            if (pos == 0) { // T is multiple of 3
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}