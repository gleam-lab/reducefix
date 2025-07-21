#include <iostream>
#include <vector>
#include <algorithm> // 引入算法库以使用lower_bound和upper_bound
using namespace std;

const int MAX_N = 200005; // 设定一个合理的最大值
vector<int> x(MAX_N), p(MAX_N), sum(MAX_N); // 使用vector代替数组，更灵活且安全

int main() {
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) { // 使用0开始索引的vector
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) { // 同上，改为0开始索引的循环
        cin >> p[i];
        sum[i] = (i > 0) ? sum[i - 1] + p[i] : p[i]; // 初始化sum数组并计算前缀和
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r; // 读取查询的左右边界值l和r
        l = lower_bound(x.begin(), x.end(), l) - x.begin(); // 二分查找左边界的下标（需要检查是否越界）
        r = upper_bound(x.begin(), x.end(), r) - x.begin() - 1; // 二分查找右边界的下标（需要减1因为upper_bound会指向“下一个”位置）
        if (l > r) continue; // 如果l大于r（即没有找到对应的元素），则跳过当前查询（或处理错误情况）
        cout << sum[r] - sum[l - 1] << endl; // 输出前缀和之差（注意l-1来获取正确的索引）
    }
    return 0; // 主函数返回0表示程序正常结束
}