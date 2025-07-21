#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }

    long long T = 0;
    while (any_of(health.begin(), health.end(), [](int h) { return h > 0; })) {
        for (int i = 0; i < n; ++i) {
            if (health[i] > 0) {
                if (T % 3 == 0) {
                    health[i] -= 3;
                } else {
                    health[i] -= 1;
                }
                if (health[i] <= 0) {
                    health[i] = 0;
                }
            }
        }
        T++;
    }

    cout << T << endl;
    return 0;
}