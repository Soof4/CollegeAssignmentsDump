#include <stdio.h>


int main() {
    int num, i, total;
    int nums[10000];
    
    i = total = 0;
    scanf("%d", &num);
    
    while (num != -1) {
        if (num > 0) {
            nums[i] = num;
            total += num;
            i++;
        }
        scanf("%d", &num);
    }
    
    printf("Sonuc: %f", (float)total/i);
}

