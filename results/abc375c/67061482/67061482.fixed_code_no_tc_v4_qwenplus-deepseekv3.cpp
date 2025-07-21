#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    double current_x = 0, current_y = 0;
    double total_distance = 0;
    
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        total_distance += sqrt((current_x - x) * (current_x - x) + (current_y - y) * (current_y - y));
        current_x = x;
        current_y = y;
    }
    
    total_distance += sqrt(current_x * current_x + current_y * current_y);
    cout << fixed << setprecision(10) << total_distance << endl;
    
    return 0;
}