#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) { // Last element
            sum += data[i];
        } else {
            if (data[i + 1] > data[i]) {
                sum += 2 * data[i + 1]; // Always add doubled value if next is greater
            } else {
                sum += data[i]; // Add current if next is not greater
            }
        }
    }
    
    cout << sum << endl;
    return 0;
}