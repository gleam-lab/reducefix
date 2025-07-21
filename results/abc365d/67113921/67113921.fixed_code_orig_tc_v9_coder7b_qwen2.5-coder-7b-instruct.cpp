#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;
    cin >> N >> S;
    int wins = 0;
    char prev = ' ';
    for (char c : S) {
        if (prev == ' ') {
            prev = c;
        } else if (prev != c) {
            wins++;
            prev = c;
        }
    }
    cout << wins + 1 << endl;
    return 0;
}