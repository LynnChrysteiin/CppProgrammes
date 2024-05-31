#include <stdio.h>

int main() {
    int door;
    while ((scanf("%d", &door)!=EOF)) {
        if (door<1||door>40) printf("error");
        else if (((door%5==0)||(door%5==1))&&(door!=1)&&(door!=40)) printf("Y");
        else printf("N");
    }
    return 0;
}