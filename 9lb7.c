
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "RUS");
    while (1) 
    {
        setlocale(LC_ALL, "Rus");
        char ch;
        int height, width;

        printf("Введите символ из которого будет строиться фигура:\n");
        // Пробел перед '%c' костыль, если в буфере будет '\n' программа его скипнет
        scanf(" %c", &ch);

        printf("Введите высоту:\n");
        scanf("%d", &height);

        printf("Введите ширину:\n");
        scanf("%d", &width);

        printf("Результат:\n\n");

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    printf("%c", ch);
                }
                else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");

        int choice;
        printf("Продолжить? (Да - введите любое число, Нет - введите 0)\n");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
    }

    return 0;
}