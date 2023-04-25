#include <stdio.h>

int main()
{ 
    int y = 10;
    int count = 0;
    while (y--) {
        ++count;
        printf("%d:y=%d\n", count, y);
    }
    // 中文显示
    printf("xianshi测试:%d\n", y); 
    return 0;
}