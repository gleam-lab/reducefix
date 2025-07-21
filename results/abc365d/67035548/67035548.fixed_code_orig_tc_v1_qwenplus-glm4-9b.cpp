#include <iostream>
#include <string>

using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    return 'S';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int prev = ' ', count = 0;
    int maxCount = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != prev) {
            prev = s[i];
            count = 1;
        } else {
            count++;
        }
        maxCount = max(maxCount, count);
    }
    cout << maxCount << endl;
    return 0;
}