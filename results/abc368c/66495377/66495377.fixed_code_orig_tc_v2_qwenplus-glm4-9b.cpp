#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t = 0;
    while (n > 0) {
        if (t % 3 == 0) {
            if (n <= 3) {
                t += n;
                n = 0;
            } else {
                t += 3;
                n -= 3;
            }
        } else {
            t += 1;
            n -= 1;
        }
    }
    cout << t << endl;
    return 0;
}