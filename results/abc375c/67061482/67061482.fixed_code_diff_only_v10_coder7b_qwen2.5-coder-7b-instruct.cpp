#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long a = 0, b = 0, x, y;
    double sum = 0;
    
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        sum += hypot(x - a, y - b); // Using hypot function for better precision
        a = x;
        b = y;
    }
    sum += hypot(a, b); // Add the distance back to the origin
    
    cout.precision(15); // Set precision to handle large numbers accurately
    cout << sum << endl;
    return 0;
}