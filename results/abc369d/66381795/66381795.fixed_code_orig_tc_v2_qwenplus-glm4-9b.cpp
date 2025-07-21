#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    
    for(int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        if (i == n - 1 || data[i + 1] * 2 > data[i] + data[i + 1]) {
            sum += data[i] * 2;
        } else {
            sum += data[i];
        }
    }
    
    cout << sum << endl;
    return 0;
}