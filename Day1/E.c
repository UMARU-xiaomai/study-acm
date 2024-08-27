#include <stdio.h>
#include <stdlib.h>

// 函数声明
void calculateMaxArea();

int main() {
    calculateMaxArea();
    return 0;
}

void calculateMaxArea() {
    int *rects = NULL;
    int *que = NULL;
    int rectSize;
    int queSize;
    int resSize = 0;
    int *res = NULL;

    while (1) {
        // 动态分配内存用于输入
        rects = (int *)malloc(1000 * sizeof(int));
        if (rects == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        // 读取一行输入并解析为整数
        rectSize = 0;
        while (scanf("%d", &rects[rectSize]) && rects[rectSize] != 0) {
            rectSize++;
        }

        if (rectSize == 0) {
            free(rects);
            break;
        }

        que = (int *)malloc(rectSize * sizeof(int));
        if (que == NULL) {
            printf("Memory allocation failed\n");
            free(rects);
            exit(1);
        }

        int max_mianji = 0;
        queSize = 0;

        for (int i = 0; i < rectSize; i++) {
            int pt = queSize - 1;
            while (pt >= 0 && que[pt] > rects[i]) {
                que[pt] = rects[i];
                pt--;
            }
            queSize = pt + 2;
            que[queSize - 1] = rects[i];
            for (int l = 0; l < queSize; l++) {
                int tmp = (queSize - l) * que[l];
                if (tmp > max_mianji) {
                    max_mianji = tmp;
                }
            }
        }

        resSize++;
        res = (int *)realloc(res, resSize * sizeof(int));
        if (res == NULL) {
            printf("Memory allocation failed\n");
            free(rects);
            free(que);
            exit(1);
        }

        res[resSize - 1] = max_mianji;
        free(rects);
        free(que);
    }

    for (int i = 0; i < resSize; i++) {
        printf("%d\n", res[i]);
    }

    free(res);
}
