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
    int pos = 0; // current position in the cycle: 0 -> next attack is normal (1 dmg), 1 -> next is normal, 2 -> next is triple (3 dmg)

    for (int i = 0; i < N; ++i) {
        while (H[i] > 0) {
            T++;
            pos = (pos + 1) % 3;

            if (pos == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }

    cout << T << endl;
    return 0;
}