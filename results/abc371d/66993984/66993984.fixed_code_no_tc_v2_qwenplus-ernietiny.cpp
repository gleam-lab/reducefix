#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n; // 输入数据点个数
    
    // 初始化数组和映射
    vector<int> x(n), p(n);
    map<int, int> sum; // 假设sum是一个map，用于存储前缀和
    
    // 处理输入数据
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> p[i]; // 读入每个数据点的值和前缀和
        sum[p[i]]++; // 对前缀和进行累加，确保每个前缀和只出现一次
    }
    
    // 处理查询请求
    while (q--) {
        int L, R; // 查询区间左端点和右端点
        cin >> L >> R; // 读入查询区间左端点和右端点
        int c = lower_bound(x.begin(), x.end(), L) - x.begin(); // 使用lower_bound查找前缀和在sum中的位置
        int d = upper_bound(x.begin(), x.end(), R) - x.begin(); // 使用upper_bound查找右端点对应的区间内的前缀和差值
        // 由于sum是一个map，这里需要从map中减去对应的前缀和差值，而不是直接赋值给变量c或d
        cout << sum[d - sum[L - 1]] << endl; // 输出查询区间内的前缀和差值
    }
    
    return 0; // 返回0表示程序正常结束
}