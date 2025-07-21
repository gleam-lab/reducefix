#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    long long T = 0;
    for (int health : H) {
        if (health > 0) {
            T += (health + 2) / 3; // Increase T by the number of full 3-damage attacks needed
        }
    }

    cout << T << endl;

    return 0;
}