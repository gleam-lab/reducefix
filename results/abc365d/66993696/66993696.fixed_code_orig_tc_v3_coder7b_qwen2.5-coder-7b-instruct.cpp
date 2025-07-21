#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Convert the first character to the opposite of itself
    if (s[0] == 'P') s[0] = 'S';
    else if (s[0] == 'R') s[0] = 'P';
    else s[0] = 'R';

    // Count the number of changes needed to make all adjacent characters different
    int changes = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            ++changes;
            if (s[i] == 'P') s[i] = 'S';
            else if (s[i] == 'R') s[i] = 'P';
            else s[i] = 'R';
        }
    }

    // The maximum number of elements that can be selected is n minus the number of changes
    cout << n - changes << endl;

    return 0;
}