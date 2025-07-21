#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') {
        return y == 'P' ? 0 : (y == 'S' ? 1 : -1);
    } else if (x == 'R') {
        return y == 'P' ? -1 : (y == 'S' ? 1 : 0);
    } else if (x == 'S') {
        return y == 'P' ? -1 : (y == 'R' ? -1 : 0);
    } else {
        return -100; // Assuming 'X' is always considered the lowest
    }
}

int win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    int maxCount = 0;
    int count = 0;
    char prev = 'X';

    // Counting from start to end
    for (int i = 0; i < n; ++i) {
        if (cmp(prev, s[i]) < 0) {
            count++;
            prev = s[i];
        } else {
            maxCount = max(maxCount, count);
            count = 1;
            prev = s[i];
        }
    }
    maxCount = max(maxCount, count);

    count = 0;
    prev = 'X';
    // Counting from end to start
    for (int i = n - 1; i >= 0; --i) {
        if (cmp(prev, s[i]) < 0) {
            count++;
            prev = s[i];
        } else {
            maxCount = max(maxCount, count);
            count = 1;
            prev = s[i];
        }
    }
    maxCount = max(maxCount, count);

    cout << maxCount << endl;
    return 0;
}