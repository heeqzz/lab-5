#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>
int main() {
	setlocale(LC_ALL, "Russian");

	int n = 10, ** G = NULL, size = 0, size2 = 0, * deg = NULL;

	printf("Введите количество вершин: ");
	scanf_s("%d", &n);

	// Выделение памяти для матрицы смежности
	G = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		G[i] = (int*)malloc(n * sizeof(int));
	}

	// Выделение памяти для массива степеней вершин
	deg = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		deg[i] = 0;
	}

	// Инициализация генератора случайных чисел
	srand(time(NULL));

	// Заполнение матрицы смежности
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			G[i][j] = rand() % 2; // Случайное значение 0 или 1
			G[j][i] = G[i][j]; // Симметричное заполнение

			// Обнуление диагональных элементов
			if (i == j) {
				G[i][j] = 0;
			}
		}
	}

	// Вывод матрицы смежности
	printf("Матрица смежности:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

	// Подсчет размера графа
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			size2 += G[i][j];
			if (G[i][j] != 0) {
				size++;
			}
		}
	}
	size = size / 2; // Корректировка размера графа
	printf("Размер графа = %d\n", size);

	// Подсчет степеней вершин
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (G[i][j] != 0) {
				deg[i]++;
			}
		}
	}

	// Вывод степеней вершин и их характеристик
	for (int i = 0; i < n; i++) {
		printf("Степень вершины %d = %d\n", i, deg[i]);
		if (deg[i] == 0) {
			printf("Вершина %d - изолированная\n", i);
		}
		if (deg[i] == 1) {
			printf("Вершина %d - концевая\n", i);
		}
		if (deg[i] == n - 1) {
			printf("Вершина %d - доминирующая\n", i);
		}
	}

	// Освобождение памяти
	for (int i = 0; i < n; i++) {
		free(G[i]);
	}
	free(G);
	free(deg);

	return 0;
}