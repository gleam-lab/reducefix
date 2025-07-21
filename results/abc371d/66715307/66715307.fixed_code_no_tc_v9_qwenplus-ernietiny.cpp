#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x[200050], p[200050], q; // 假设输入都是整数
    cin >> n; // 输入数据量
    for (int i = 1; i <= n; i++) { // 从第1个元素开始读取数据
        cin >> x[i];
    }
    
    // 修复代码逻辑，保证连续的递增数组不会越界
    for (int i = 1; i < n; i++) { // 注意边界条件检查
        cin >> p[i];
        x[i] += p[i]; // 直接累加而不是修改数组元素
    }
    
    // ...其余代码保持不变...
    
    // 修复输出格式，确保输出结果正确无误
    cout << fixed << setprecision(1) << a[l2] - a[l1 - 1] << endl; // 使用固定小数点输出格式，并确保输出结果正确无误
    
    return 0; // 返回0表示程序正常结束
}