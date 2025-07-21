#include <iostream>
#include <unordered_map>
using namespace std;

int cmp(char x, char y) {
    if (x == 'P') {
        return (y == 'R')? 1 : (y == 'S')? -1 : 0;
    }
    if (x == 'R') {
        return (y == 'S')? 1 : (y == 'P')? -1 : 0;
    }
    if (x == 'S') {
        return (y == 'P')? 1 : (y == 'R')? -1 : 0;
    }
    return -100; // Not a playing character
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    unordered_map<char, int> lastPlay;
    int ans = 0;
    char prev = 'X';
    
    for (int i = 0; i < n; ++i) {
        char current = s[i];
        char winChar = (current == 'X')? 'X' : (lastPlay[current] == 'X')? 'X' : (lastPlay[current] == 'X')? 'X' : cmp(lastPlay[prev], current);

        if (winChar != 'X') {
            ans++;
            lastPlay[prev] = winChar;
        }
        prev = current;
    }

    cout << ans;
    return 0;
}