#include <iostream>
#include <vector>
#include <algorithm> // 包含排序所需的头文件
using namespace std;

int n, q;
vector<int> x, p; // 使用vector代替数组，更灵活且易读
long long sum[200005]; // 修改为long long以防止溢出

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) { // 从0开始初始化vector中的元素，并考虑范围为1开始的偏移量
        cin >> x[i];
    }
    sort(x.begin(), x.end()); // 对x进行排序，以支持lower_bound和upper_bound的调用
    for (int i = 1; i <= n; i++) { // 从1开始，并使用sum数组计算p的前缀和
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // 注意sum数组也需更新以支持查询操作
    }
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R; // 读取查询的左右边界值L和R
        // 修改后的lower_bound和upper_bound的使用，这里要考虑到数组索引的偏移量
        int l = lower_bound(x.begin(), x.end(), L) - x.begin() + 1; // 加上1是因为数组索引从1开始
        int r = upper_bound(x.begin(), x.end(), R) - x.begin(); // 注意这里不需要加1，因为upper_bound会考虑在容器内的下一个位置，并自动调整为有效的数组索引值
        // 计算前缀和的差值，并输出结果（这里也修改了前缀和的索引问题）
        cout << sum[r] - sum[l - 1] << endl; // 注意这里l-1是因为我们希望计算的是从第L个元素到第R个元素之前的所有元素的p值之和
    }
    return 0; // 主函数应返回一个整型值（虽然在这里不严格必要）
}