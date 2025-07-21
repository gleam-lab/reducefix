#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 0, b = 0, c, d, cou = 0;
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> c >> d;
        cou += sqrt((a-c)*(a-c) + (b-d)*(b-d));
        a = c;
        b = d;
    }
    cou += sqrt(a*a + b*b); // This line was missing in your original code
    cout.precision(15); // Ensuring enough precision for floating point comparison
    cout << cou << endl;
}