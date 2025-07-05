#pragma once
#include "lib.h"

const int ROWS = 3;   
const int COLS = 3;   

void  matrixFloatSredArefStatic() {
	srand(time(nullptr));
    float matrix[ROWS][COLS];
    float res[COLS];            // ������� ��, ������� ��������

    // ��������� �������
    for (int r = 0; r < ROWS; ++r)
        for (int c = 0; c < COLS; ++c)
            matrix[r][c] = (rand() % 10000) / 100.0f;

    // ������ �������
    cout << "Matrix:\n";
    for (int r = 0; r < ROWS; ++r) {
        cout << '|';
        for (int c = 0; c < COLS; ++c)
            cout << setw(8) << fixed << setprecision(2) << matrix[r][c] << ' ';
        cout << "|\n";
    }

    // ������� �� ������� �������
    for (int c = 0; c < COLS; ++c) {
        float sum = 0;
        for (int r = 0; r < ROWS; ++r)
            sum += matrix[r][c];          // r � ������, c � �������
        res[c] = sum / ROWS;              // ����� �� ���������� �����
    }

    cout << "sred aref|";
    for (int c = 0; c < COLS; ++c)
        cout << setw(8) << fixed << setprecision(2) << res[c] << ' ';
    cout << "|\n";
}

void matrixFloatSredArefDynamic(int ROW, int COL) {
	srand(time(nullptr)); // ���������� ��� ��������� ��������� �����

	float** matrix; // ������������ �������
	float* res; // ������������ ������ ��� �������� �������� �������� �� ��������

	matrix = new float* [ROW]; // �������� ������ ��� ����� �������
    res = new float[COL]; // �������� ������ ��� ������� �������� ��������

	for (int i = 0; i < ROW; ++i) 
		matrix[i] = new float[COL]; // �������� ������ ��� ������� �������

    for (int r = 0; r < ROW; ++r)
        for (int c = 0; c < COL; ++c)
			matrix[r][c] = (rand() % 10000) / 100.0f; // ��������� ������� ���������� �������

    for (int r = 0; r < ROW; ++r) {
        for (int c = 0; c < COL; ++c)
			printf("%-+6.2f | ", matrix[r][c]); // ������ ������� � ���������������
		printf("\n"); // ����������� �����
    }

    for (int c = 0; c < COL; ++c) {
		float sum = 0; // ���������� ��� �������� ����� ��������� �������
        for (int r = 0; r < ROW; ++r) {
			sum += matrix[r][c]; // ��������� �������� �������
        }

		res[c] = sum / (float)COL; // ��������� ������� �������� �� �������
			   
    }
   
	for (int i = 0; i < COL; ++i) {
		printf("%6.2f |", res[i]); // ������ �������� �������� �� ��������
	}

	for (int i = 0; i < ROW; ++i)  // ����������� ������, ���������� ��� ����� �������
		delete[] matrix[i]; // ����������� ������ ��� ������� �������
	delete[] matrix; // ����������� ������ ��� ������� ����� �������
    matrix = nullptr;  

	delete[] res;
	res = nullptr;

}

void matrixFloatSredArefDynamic�(int ROW, int COL) {
    srand((unsigned int)time(NULL)); // ������������� ���������� ��������� �����

    float** matrix = (float**)malloc(ROW * sizeof(float*));  // �������� ������ ��� �����
    float* res = (float*)malloc(COL * sizeof(float));        // �������� ������ ��� ����������

 
    for (int i = 0; i < ROW; ++i) {
        matrix[i] = (float*)malloc(COL * sizeof(float));     // �������� ������ ��� ������� �������
        
    }

    // ��������� ������� ���������� �������
    for (int r = 0; r < ROW; ++r)
        for (int c = 0; c < COL; ++c)
            matrix[r][c] = (rand() % 10000) / 100.0f;

    // �������� �������
    for (int r = 0; r < ROW; ++r) {
        for (int c = 0; c < COL; ++c)
            printf("%-+6.2f | ", matrix[r][c]);
        printf("\n");
    }

    // ��������� ������� �� ��������
    for (int c = 0; c < COL; ++c) {
        float sum = 0.0f;
        for (int r = 0; r < ROW; ++r)
            sum += matrix[r][c];
        res[c] = sum / ROW;  // ������� �� ������� (����� �� ����� �����)
    }

    // �������� ������� ��������
    for (int c = 0; c < COL; ++c)
        printf("%6.2f | ", res[c]);
    printf("\n");

    // ����������� ������
    for (int i = 0; i < ROW; ++i)
        free(matrix[i]);
    free(matrix);
    free(res);
}