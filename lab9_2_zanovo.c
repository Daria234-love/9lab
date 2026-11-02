#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "Russian");

    char answer;

    do
    {
        char number[101];
        int count = 0;

        printf("Введите целое число: ");
        scanf("%100s", number);

        for (int i = 0; number[i] != '\0'; i++)
        {
            if (number[i] == '3')
            {
                count++;
            }
        }

        printf("Количество цифр 3 в числе: %d\n", count);

        printf("Продолжить? (y — да, n — нет): ");
        scanf(" %c", &answer);

    } while (answer == 'y' || answer == 'Y');

    printf("Программа завершена.\n");

    return 0;
}