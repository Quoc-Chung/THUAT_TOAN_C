#include <stdio.h>

int main() {
    int width = 30;
    int height = 20;
    int x, y;
    char heart = '*';

    // Vẽ hình trái tim
    for (y = -height / 2; y <= height / 2; y++) {
        for (x = -width / 2; x <= width / 2; x++) {
            if ((x * x + y * y - 1) * (x * x + y * y - 1) * (x * x + y * y - 1) - x * x * y * y * y <= 0) {
                printf("%c", heart);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}