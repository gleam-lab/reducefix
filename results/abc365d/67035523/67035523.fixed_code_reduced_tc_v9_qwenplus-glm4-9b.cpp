#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int consecutiveRocks = 0;
    bool lastWasP = false;

    for (char c : s) {
        if (c == 'R') {
            if (lastWasP) {
                consecutiveRocks++;
                lastWasP = false;
            }
        } else if (c == 'P') {
            lastWasP = true;
        }
    }

    cout << consecutiveRocks + 1;
    return 0;
}