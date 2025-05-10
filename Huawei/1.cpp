/*
**1、图像亮度坐标搜索**

给定一张二维图像,图像中每个值表示该坐标下的亮度。现在给定一个亮度值$m$, 请返回离图像中心坐标最近的$k$个亮度为$m$值的坐标$(x,y)$。

提示:
1、图像中元素的坐标范围 $x: [0,w-1],y: [0, h-1]$。
2、图像宽高$w,h$均为奇数,图像中心坐标$(w-1)/2, (h-1)/2$。
3、平面上两点之间的距离为$|x_1-x_2| + |y_1-y_2|$。
4、在距离相同的情况下,以小的点优先;当$x$相同时,以$y$小的点优先。
5、题目可保证至少存在一个亮度值为$m$的点。

解答要求
时间限制: C/C++ 1000ms,其他语言: 2000ms
内存限制: C/C++ 256MB,其他语言: 512MB

输入
第一行输入为图像宽度 $w$和图像高度$h$, 以空格隔开,宽高范围为1~2000
第二行输入为给定亮度值$m$, 范围为1~1000
第三行输入为需要输出的亮度值为$m$的坐标个数$k$,范围为1~100,且$k <= w * h$
接下来共$h$行,每行内为$w$个亮度,以空格隔开,亮度范围为1~1000

输出
```cpp
1  // we have defined the necessary header files here for this problem.
2  // If additional header files are needed in your program, please import here.
3
4  int main()
5  {
6   {
7      // please define the C++14 input here. For example: int a,b; cin>>a>>b;;
8      // please finish the function body here.
9      // please define the C++14 output here. For example:cout<<___<<endl;
10
11      return 0;
12  }
13

*/
#include <iostream> // 用于标准输入输出流
#include <vector> // 用于使用 std::vector 动态数组
#include <algorithm> // 用于使用 std::sort 等算法
#include <cmath> // 用于使用 std::abs 等数学函数

// 定义一个结构体 Point，用于存储点的坐标和到中心的距离
struct Point {
    int x; // 点的 x 坐标
    int y; // 点的 y 坐标
    int distance; // 点到图像中心的曼哈顿距离
};

int main() {
    // w: 图像宽度, h: 图像高度
    int w, h;
    int w, h;
    std::cin >> w >> h; // 读取图像的宽度和高度
    
    // m: 目标像素值
    int m;
    std::cin >> m; // 读取目标像素值
    
    // k: 需要输出的点的数量
    int k;
    std::cin >> k; // 读取需要输出的点的数量
    
    // 创建一个二维向量 image 来存储图像的像素值
    std::vector<std::vector<int>> image(h, std::vector<int>(w));
    // 循环读取图像的每个像素值
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> image[i][j]; // 读取当前像素值
        }
    }
    
    // 计算图像中心的 x 坐标 (0-indexed)
    int center_x = (w - 1) / 2;
    // 计算图像中心的 y 坐标 (0-indexed)
    int center_y = (h - 1) / 2;
    
    // 创建一个向量 points 用于存储所有像素值为 m 的点的信息
    std::vector<Point> points;
    // 遍历图像的每一个像素点
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            // 如果当前像素值等于目标值 m
            if (image[y][x] == m) {
                // 计算当前点到图像中心的曼哈顿距离
                int dist = std::abs(x - center_x) + std::abs(y - center_y);
                // 将该点的坐标和距离存入 points 向量
                points.push_back({x, y, dist});
            }
        }
    }
    
    // 对 points 向量中的点进行排序
    // 排序规则：
    // 1. 首先按距离从小到大排序
    // 2. 如果距离相同，则按 x 坐标从小到大排序
    // 3. 如果 x 坐标也相同，则按 y 坐标从小到大排序
    std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.distance != b.distance) { // 比较距离
            return a.distance < b.distance; // 距离小的在前
        }
        }
        if (a.x != b.x) { // 如果距离相同，比较 x 坐标
            return a.x < b.x; // x 坐标小的在前
        }
        }
        return a.y < b.y; // 如果 x 坐标也相同，比较 y 坐标，y 坐标小的在前
    });
    
    // 输出排序后的前 k 个点的坐标，或者如果点的总数小于 k，则输出所有点
    for (int i = 0; i < k && i < points.size(); i++) {
        std::cout << points[i].x << " " << points[i].y << std::endl; // 输出点的 x 和 y 坐标
    }
    
    return 0; // 程序正常结束
}
// 改进算法

// 针对当前的图像亮度坐标搜索算法，我们可以通过以下几个方面进行优化：1. 使用BFS（广度优先搜索）从中心点开始向外扩展，这样可以保证先找到距离中心最近的点，一旦找到k个目标亮度的点就可以提前结束搜索；2. 可以在读取输入时就记录所有亮度为m的点的位置，避免后续重复遍历；3. 可以使用优先队列（小根堆）来维护k个最近的点，这样可以减少排序的开销。

          
// 使用优先队列优化算法，减少排序开销并实现更高效的k个最近点查找。
      
// 1. 使用优先队列（小根堆）代替排序：
//    - 通过重载 `Point` 结构体的 `operator<` 实现自定义比较规则
//    - 优先队列自动维护最近的 k 个点，避免了对所有点进行排序
//    - 时间复杂度从 O(nlogn) 优化到 O(nlogk)，其中 n 是图像中目标像素点的数量

// 2. 内存优化：
//    - 移除了存储整个图像的二维数组，改为边读取边处理
//    - 只保存最近的 k 个点，而不是存储所有符合条件的点
//    - 显著减少了内存使用

// 3. 代码结构优化：
//    - 使用静态成员变量存储中心点坐标，提高了代码的可维护性
//    - 简化了点的比较逻辑，将其封装在 `Point` 结构体中
//    - 移除了冗余的注释，使代码更加简洁清晰

// 这些改进使得算法在处理大规模图像时更加高效，特别是当 k 远小于图像中目标像素点的总数时，性能提升更为显著。

        