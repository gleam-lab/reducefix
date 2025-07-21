#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    int px = 0, py = 0;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        ans += std::hypot(x - px, y - py);
        px = x;
        py = y;
    }
    
    // After the loop, px and py are the coordinates of the last point
    // We need to add the distance from the last point back to the origin
    ans += std::hypot(px, py);
    
    // Print the result with a precision of 10 decimal places
    std::cout.precision(10);
    std::cout << std::fixed << ans << std::endl;
    
    return 0;
}