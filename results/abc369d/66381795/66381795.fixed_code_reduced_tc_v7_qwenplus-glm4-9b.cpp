#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n, a;
int main() {
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    ll sum = 0;
    bool add_double = true;  // Start with adding single element
    for (int i = 0; i < n; i++) {
        if (add_double) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
        add_double = !add_double;  // Toggle between adding single and double value
    }
    cout << sum << endl;
    return 0;
}