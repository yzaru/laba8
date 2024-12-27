#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_NODES 10  // Определите количество вершин графа
// Функция для генерации случайной матрицы смежности для неориентированного графа
void generateAdjacencyMatrix(int matrix[MAX_NODES][MAX_NODES], int numNodes) {
    srand(time(NULL));
    for (int i = 0; i < numNodes; i++) {
        for (int j = i; j < numNodes; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = matrix[j][i] = rand() % 2;  // Случайное значение 0 или 1
            }
        }
    }
}
// Функция для вывода матрицы смежности на экран
void printAdjacencyMatrix(int matrix[MAX_NODES][MAX_NODES], int numNodes) {
    printf("Матрица смежности:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
// Реализация обхода в ширину (BFS) для графа с использованием очереди
void bfs(int matrix[MAX_NODES][MAX_NODES], int numNodes, int startNode) {
    bool visited[MAX_NODES] = {false};
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    visited[startNode] = true;
    queue[rear++] = startNode;
    printf("Обход в ширину начиная с вершины %d: ", startNode);
    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);
        for (int i = 0; i < numNodes; i++) {
            if (matrix[currentNode][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
// Основная функция
int main() {
    int numNodes = MAX_NODES;
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    // Генерация и вывод матрицы смежности
    generateAdjacencyMatrix(adjacencyMatrix, numNodes);
    printAdjacencyMatrix(adjacencyMatrix, numNodes);
    // Выполнение обхода в ширину
    bfs(adjacencyMatrix, numNodes, 0);
    return 0;
}