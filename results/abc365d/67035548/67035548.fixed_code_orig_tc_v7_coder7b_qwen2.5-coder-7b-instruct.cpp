#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 0, sub = 0;
    char prev = '\0';

    for (int i = 0; i < n; ++i) {
        if (prev != s[i]) {
            ++ans;
            prev = s[i];
        }
    }

    prev = '\0';
    for (int i = n - 1; i >= 0; --i) {
        if (prev != s[i]) {
            ++sub;
            prev = s[i];
        }
    }

    cout << max(ans, sub);
    return 0;
}