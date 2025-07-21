#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int win(char x, char y) {
    if (x == 'R' && y == 'S') return 1;
    if (x == 'S' && y == 'R') return -1;
    if (x == 'P' && y == 'R') return -1;
    if (x == 'R' && y == 'P') return 1;
    if (x == 'S' && y == 'P') return 1;
    if (x == 'P' && y == 'S') return -1;
    if (x == 'X') return -100;
    return 0;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    unordered_map<char, int> count;
    for (char c : s) {
        count[c]++;
    }

    if (count['P'] == 0 || count['R'] == 0 || count['S'] == 0) {
        cout << 0 << endl;
        return 0;
    }

    int max_subsequence = 0;
    for (char c : {'P', 'R', 'S'}) {
        max_subsequence += count[c] - 1; // Subtract one as each character can only win once in a sequence
    }

    cout << max_subsequence + 1 << endl; // +1 for the last element in the sequence
    return 0;
}