#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    set<int> captured_rows, captured_cols, captured_diag1, captured_diag2, captured_rdiag1, captured_rdiag2;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--; // Convert to 0-based index
        b--;
        
        if (captured_rows.insert(a).second) {
            captured_diag1.insert(b + a);
            captured_diag2.insert(a - b);
            captured_rdiag1.insert(-a + b + n - 1);
            captured_rdiag2.insert(-b - a + n - 1);
        }
        
        if (captured_cols.insert(b).second) {
            captured_diag1.insert(b + a);
            captured_diag2.insert(a - b);
            captured_rdiag1.insert(-a + b + n - 1);
            captured_rdiag2.insert(-b - a + n - 1);
        }
        
        captured_diag1.insert(a + b + n - 1);
        captured_diag2.insert(-a + b + n - 1);
        captured_rdiag1.insert(a + b + n - 1);
        captured_rdiag2.insert(-a - b + n - 1);
    }
    
    int count = n * n;
    
    // Subtract captured rows, columns
    for (int x : captured_rows) count--;
    for (int x : captured_cols) count--;
    
    // Subtract overlap
    for (int x : captured_diag1) count--;
    for (int x : captured_diag2) count--;
    for (int x : captured_rdiag1) count--;
    for (int x : captured_rdiag2) count--;
    
    cout << count << endl;
    
    return 0;
}