#pragma once
#include "lib.h"

const int ROWS = 3;   
const int COLS = 3;   

void  matrixFloatSredArefStatic() {
	srand(time(nullptr));
    float matrix[ROWS][COLS];
    float res[COLS];            // столько же, сколько столбцов

    // заполняем матрицу
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c)
            matrix[r][c] = (rand() % 10000) / 100.0f;

    // печать матрицы
    cout << "Matrix:\n";
    for (int r = 0; r < ROWS; ++r) {
        cout << '|';
        for (int c = 0; c < COLS; ++c)
            cout << setw(8) << fixed << setprecision(2) << matrix[r][c] << ' ';
        cout << "|\n";
    }

    // среднее по каждому столбцу
    for (int c = 0; c < COLS; ++c) {
        float sum = 0;
        for (int r = 0; r < ROWS; ++r)
            sum += matrix[r][c];          // r – строка, c – столбец
        res[c] = sum / ROWS;              // делим на количество строк
    }

    cout << "sred aref|";
    for (int c = 0; c < COLS; ++c)
        cout << setw(8) << fixed << setprecision(2) << res[c] << ' ';
    cout << "|\n";
}

void matrixFloatSredArefDynamic(int ROW, int COL) {
	srand(time(nullptr)); // необходимо для генерации случайных чисел

	float** matrix; // динамическая матрица
	float* res; // динамический массив для хранения среднего значения по столбцам

	matrix = new float* [ROW]; // выделяем память для строк матрицы
    res = new float[COL]; // выделяем память для массива среднего значения

	for (int i = 0; i < ROW; ++i) 
		matrix[i] = new float[COL]; // выделяем память для каждого столбца

    for (int r = 0; r < ROW; ++r)
        for (int c = 0; c < COL; ++c)
			matrix[r][c] = (rand() % 10000) / 100.0f; // заполняем матрицу случайными числами

    for (int r = 0; r < ROW; ++r) {
        for (int c = 0; c < COL; ++c)
			printf("%-+6.2f | ", matrix[r][c]); // печать матрицы с форматированием
		printf("\n"); // разделитель строк
    }

    for (int c = 0; c < COL; ++c) {
		float sum = 0; // переменная для хранения суммы элементов столбца
        for (int r = 0; r < ROW; ++r) {
			sum += matrix[r][c]; // суммируем элементы столбца
        }

		res[c] = sum / (float)COL; // вычисляем среднее значение по столбцу
			   
    }
   
	for (int i = 0; i < COL; ++i) {
		printf("%6.2f |", res[i]); // печать среднего значения по столбцам
	}

	for (int i = 0; i < ROW; ++i)  // освобождаем память, выделенную для строк матрицы
		delete[] matrix[i]; // освобождаем память для каждого столбца
	delete[] matrix; // освобождаем память для массива строк матрицы
    matrix = nullptr;  

	delete[] res;
	res = nullptr;

}

void matrixFloatSredArefDynamicС(int ROW, int COL) {
    srand((unsigned int)time(NULL)); // инициализация генератора случайных чисел

    float** matrix = (float**)malloc(ROW * sizeof(float*));  // выделяем память для строк
    float* res = (float*)malloc(COL * sizeof(float));        // выделяем память для результата

 
    for (int i = 0; i < ROW; ++i) {
        matrix[i] = (float*)malloc(COL * sizeof(float));     // выделяем память для каждого столбца
        
    }

    // Заполняем матрицу случайными числами
    for (int r = 0; r < ROW; ++r)
        for (int c = 0; c < COL; ++c)
            matrix[r][c] = (rand() % 10000) / 100.0f;

    // Печатаем матрицу
    for (int r = 0; r < ROW; ++r) {
        for (int c = 0; c < COL; ++c)
            printf("%-+6.2f | ", matrix[r][c]);
        printf("\n");
    }

    // Вычисляем среднее по столбцам
    for (int c = 0; c < COL; ++c) {
        float sum = 0.0f;
        for (int r = 0; r < ROW; ++r)
            sum += matrix[r][c];
        res[c] = sum / ROW;  // среднее по столбцу (делим на число строк)
    }

    // Печатаем средние значения
    for (int c = 0; c < COL; ++c)
        printf("%6.2f | ", res[c]);
    printf("\n");

    // Освобождаем память
    for (int i = 0; i < ROW; ++i)
        free(matrix[i]);
    free(matrix);
    free(res);
}