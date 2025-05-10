/*
**编程题 第2/3题**

假设我们有一颗装满彩灯的二叉树，树的每个节点代表一个灯泡。每个灯泡有三种颜色状态：红色(用整数1表示)、绿色(用整数2表示)和蓝色(用整数3表示)。每个节点上都配有一个开关，当按下某个
节点的开关时，以该节点为根节点的子树上所有节点的灯泡颜色都会根据当前的颜色按照"红-> 绿->蓝->红->...”的循环切换顺序切换一次颜色。
给定二叉树的初始颜色状态 initial 和目标颜色状态 target,两者都以层序遍历的——维整数数组的形式表示,数组元素对应二叉树层序遍历的节点的颜色。如果某个节点在二叉树中不存在,则在数组中使用 0 表
示。
目标: 计算将二叉树从初始颜色状态 initial 切换到目标颜色状态 target 所需的最少开关切换次数。
解释补充:
* "层序遍历"是指从上到下、从左到右逐层遍历二叉树的节点,并将遍历结果保存在一维数组中,如果某个节点在二叉树中不存在,则在数组中使用0表示。
* 切换开关的影响是"传递性"的,即切换一个节点的开关会影响以该节点为根节点的子树上所有节点的灯泡颜色。

**解答要求**

时间限制: C/C++ 1500ms,其他语言: 3000ms
内存限制: C/C++ 256MB,其他语言: 512MB

**输入**

第一行输入为一个整数n,代表initial[]和target[]的数组大小
第二行输入为n个整数,代表initial[]的元素值
第三行输入为n个整数, target[]的元素值
参数取值范围:
* initial.lenght == targets.lenght
* 0 <= initial[i] <= 3,且为整数
* 0 <= targets[i] <= 3,且为整数
* 如果initial[i] == 0,则targets[i] == 0
* 1 <= initial.lenght <= 10^6

**输出**

一个整数,表示最少开关切换次数。
*/
#include <iostream>
#include <vector>
using namespace std;

/**
 * 计算从一种颜色切换到另一种颜色所需的最少开关次数
 * @param from 当前颜色 (1-红, 2-绿, 3-蓝)
 * @param to 目标颜色 (1-红, 2-绿, 3-蓝)
 * @return 所需的最少开关次数
 */
int getNeededSwitches(int from, int to) {
    if (from == to) return 0;  // 颜色相同，不需要切换
    if ((from % 3) + 1 == to) return 1;  // 只需切换一次 (红->绿, 绿->蓝, 蓝->红)
    return 2;  // 需要切换两次 (红->蓝, 绿->红, 蓝->绿)
}

/**
 * 计算将二叉树从初始颜色状态切换到目标颜色状态所需的最少开关次数
 * @param initial 初始颜色状态数组 (层序遍历)
 * @param target 目标颜色状态数组 (层序遍历)
 * @return 所需的最少开关次数
 */
int minSwitches(vector<int>& initial, vector<int>& target) {
    int n = initial.size();
    int totalSwitches = 0;  // 总开关次数
    
    // 记录每个节点受到父节点影响后的实际开关次数
    vector<int> switchCount(n, 0);
    
    // 自顶向下遍历每个节点
    for (int i = 0; i < n; i++) {
        // 如果节点不存在，跳过
        if (initial[i] == 0) continue;
        
        // 计算当前节点的父节点影响
        // 在二叉树的数组表示中，节点i的父节点索引为(i-1)/2
        if (i > 0) {
            int parent = (i - 1) / 2;
            // 累加父节点的开关次数影响 (对颜色的影响是循环的，所以模3)
            switchCount[i] = (switchCount[i] + switchCount[parent]) % 3;
        }
        
        // 计算当前节点的初始颜色经过之前开关操作后的颜色
        int currentColor = initial[i];
        for (int j = 0; j < switchCount[i]; j++) {
            currentColor = currentColor % 3 + 1;  // 颜色循环：红->绿->蓝->红
        }
        
        // 计算还需要多少次切换才能达到目标颜色
        int needed = getNeededSwitches(currentColor, target[i]);
        
        // 更新当前节点的开关次数和总开关次数
        switchCount[i] = (switchCount[i] + needed) % 3;
        totalSwitches += needed;
    }
    
    return totalSwitches;
}

int main() {
    int n;
    cin >> n;  // 读取数组大小
    
    // 读取初始颜色状态
    vector<int> initial(n);
    for (int i = 0; i < n; i++) {
        cin >> initial[i];
    }
    
    // 读取目标颜色状态
    vector<int> target(n);
    for (int i = 0; i < n; i++) {
        cin >> target[i];
    }
    
    // 输出最少开关切换次数
    cout << minSwitches(initial, target) << endl;
    
    return 0;
}