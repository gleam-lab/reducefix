#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int wins = 0;
    char prev = 'X';

    for (int i = 0; i < n; ++i) {
        if (prev != s[i]) {
            ++wins;
            prev = s[i];
        }
    }

    cout << wins << endl;
    return 0;
}