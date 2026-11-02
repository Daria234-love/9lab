#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define MAX_DIGITS 12 // покрывает длину int32

int main() {
	int value;
	setlocale(LC_ALL, "Russian");
	printf("Введите число:\n");
	scanf(" %d", &value);

	int temp = abs(value);

	int digits[MAX_DIGITS];
	int totalDigits;

	if (temp == 0) {
		digits[0] = 0;
		totalDigits = 1;
	}
	else {
		int reverse_digits[MAX_DIGITS];
		int count = 0;
		while (temp > 0) 
		{
			reverse_digits[count++] = temp % 10;
			temp /= 10;
		}
		for (int i = 0; i < count; i++) 
		{
			digits[i] = reverse_digits[count - 1 - i];
		}
		totalDigits = count;
	}

	int countThrees = 0; // 1
	int countLastDigitRep = 0; // 2
	int countEvens = 0; // 3
	int countGreaterThanFive = 0; // 4
	int sumOdds = 0; // 5
	int sumGreaterEqualSeven = 0; // 6
	long long productnonZero = 1; // 7 - Можем получить ошибку, либо переполнение буфера. Тут нужно быть аккуратным с вводим числом
	int sumEvensExceptLast = 0; // 9 (8 пропустили, она будет считаться из существующих)
	bool hasAdjacentIdentical = false; // 10
	int sumEvenPositions = 0; // 12 (11 аналогично как с 8, будет считаться из существующего)
	int sumOddPositions = 0; // 12

	int lastDigit = digits[totalDigits - 1];
	for (int i = 0; i < totalDigits; i++) {
		int d = digits[i];

		// 1
		if (d == 3) countThrees++;

		// 2
		if (d == lastDigit) countLastDigitRep++;

		// 3
		if (d % 2 == 0) countEvens++;

		// 4
		if (d > 5) countGreaterThanFive++;

		// 5
		if (d % 2 != 0) sumOdds += d;

		// 6
		if (d >= 7) sumGreaterEqualSeven += d;

		// 7
		if (d != 0) productnonZero *= d;

		// 9
		if (d % 2 == 0 && i != (totalDigits - 1)) sumEvensExceptLast += d;

		// 10
		hasAdjacentIdentical = (i > 0 && digits[i] == digits[i - 1]);

		// 12
		int positionFromRight = totalDigits - i;
		if (positionFromRight % 2 == 0) {
			sumEvenPositions += d;
		}
		else {
			sumOddPositions += d;
		}
	}

	printf("РЕЗУЛЬТАТ:\n");
	printf("1) Кол-во цифр 3: %d\n", countThrees);
	printf("2) Числа повторений последней цифры в числе (%d): %d\n", lastDigit, countLastDigitRep);
	printf("3) Кол-во чётных цифр: %d\n", countEvens);
	printf("4) Кол-во цифр больших 5: %d\n", countGreaterThanFive);
	printf("5) Сумма нечётных цифр: %d\n", sumOdds);
	printf("6) Сумма цифр больше или равно 7: %d\n", sumGreaterEqualSeven);
	printf("7) Произведение всех цифр, исключая 0: %lld\n", productnonZero);

	if (totalDigits >= 2) {
		int secondDigit = digits[1];
		int penultDigit = digits[totalDigits - 2];
		printf("8) Произведение препоследней (%d) и второй цифры (%d) числа: %lld\n",
			penultDigit, secondDigit, (long long)penultDigit * secondDigit);
	}
	else {
		printf("8) Произведение невозможно: в числе меьше 2 цифр\n");
	}

	printf("9) Сумма чётных цифр, исключая последнее число (%d): %d\n", lastDigit, sumEvensExceptLast);
	printf("10) Рядом располоденные одинаковые цифры: %s\n", hasAdjacentIdentical ? "Да" : "Нет");

	if (totalDigits % 2 == 0) {
		int mid = totalDigits / 2;
		int sumFirstHalf = 0, sumSecondHalf = 0;
		for (int i = 0; i < mid; i++) {
			sumFirstHalf += digits[i];
			sumSecondHalf += digits[mid + i];
		}
		printf("11) Сумма половин (%d и %d): %s\n", sumFirstHalf, sumSecondHalf,
			(sumFirstHalf == sumSecondHalf) ? "Равны" : "Не равны");
	}
	else {
		printf("11) Число не симметрично");
	}

	long long productOfPositions = (long long)sumEvenPositions * sumOddPositions;
	printf("12) Произведение сумм чётных (%d) и нечётных (%d) разрядов: %lld\n", sumEvenPositions, sumOddPositions, productOfPositions);
	return 0;
}