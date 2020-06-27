#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    int sum = *a + *b;
    int _abs = std::abs(*a - *b);
    *a = sum;
    *b = _abs;    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}