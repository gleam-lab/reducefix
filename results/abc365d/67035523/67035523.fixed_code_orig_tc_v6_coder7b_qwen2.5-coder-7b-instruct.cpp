#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    
    char prev = s[0];
    int count = 1;
    
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] != prev) {
            prev = s[i];
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}