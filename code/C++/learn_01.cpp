#include <stdio.h>

int main()
{ 
    int y = 10;
    int count = 0;
    while (y--) {
        ++count;
        printf("��%d��:y=%d\n", count, y);
    }
    printf("���y��ֵ:%d\n", y); 
    return 0;
}