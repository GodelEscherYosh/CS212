#include <stdio.h>

struct Point{
    int x;
    int y;

}tuple;

int main() {
    struct Point *point = &tuple;
    point->x = 10;
    point->y = 20;
    point->y++;
    printf("%d \n", point->y);
}