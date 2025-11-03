#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <iomanip>
using namespace std;

char win(char x) {
    if (x == 'R') return 'P';
    if (x == 'S') return 'R';
    if (x == 'P') return 'S';
    return 'X';
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    // Forward pass: start with first character's winner
    int forward = 0;
    char current = win(s[0]);
    for (int i = 0; i < n; i++) {
        if (s[i] != current) {
            forward++;
            current = win(s[i]);
        }
    }

    // Backward pass: start from the end and go backwards
    int backward = 0;
    current = win(s[n-1]);
    for (int i = n-1; i >= 0; i--) {
        if (s[i] != current) {
            backward++;
            current = win(s[i]);
        }
    }

    cout << max(forward, backward) << endl;
    return 0;
}