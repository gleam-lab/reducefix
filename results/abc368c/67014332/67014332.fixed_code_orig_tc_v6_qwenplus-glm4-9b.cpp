#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long t = 0, i = 0;
    
    while (i < n) {
        long long health = cin >> noskipws;
        while (health > 0) {
            if (t % 3 == 0) {
                t += (health + 2) / 3; // Use ceil for health division by 3
                health = health % 3;
            } else {
                t++;
                health--;
            }
        }
        i++;
    }
    
    cout << t << endl;
    return 0;
}