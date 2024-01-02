#include <iostream>
#include <vector>
#include "Linked_List.hpp"
#include "Quick_Sort.hpp"
#include "Graph_Algorithms.hpp"
#include "Dynamic_Programming.hpp"
#include "Matrix_Operations.hpp"
#include "Machine_Learning_Basics.hpp"
#include "Data_Compression.hpp"
#include "Algorithmic_Puzzles.hpp"


void showMenu();
void linkedListDemo();
void quickSortDemo();
void graphDemo();
void dynamicProgrammingDemo();
void matrixOperationsDemo();
void machineLearningDemo();
void dataCompressionDemo();
void algorithmicPuzzlesDemo();


int main() {
    int choice;
    bool running = true;

    while (running) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                linkedListDemo();
                break;
            case 2:
                quickSortDemo();
                break;
            case 3:
                graphDemo();
                break;
            case 4:
                dynamicProgrammingDemo();
                break;
            case 5:
                matrixOperationsDemo();
                break;
            case 6:
                machineLearningDemo();
                break;
            case 7:
                dataCompressionDemo();
                break;
            case 8:
                algorithmicPuzzlesDemo();
                break;
            case 0:
                running = false;
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}

void showMenu() {
    std::cout << "\n=== Algorithm and Data Structure Demos ===\n";
    std::cout << "1: Linked List Demo\n";
    std::cout << "2: Quick Sort Demo\n";
    std::cout << "3: Graph Algorithms Demo\n";
    std::cout << "4: Dynamic Programming Demo\n";
    std::cout << "5: Matrix Operations Demo\n";
    std::cout << "6: Machine Learning Demo\n";
    std::cout << "7: Data Compression Demo\n";
    std::cout << "8: Algorithmic Puzzles Demo\n";
    std::cout << "0: Exit\n";
    std::cout << "Enter your choice: ";
    
}


void linkedListDemo() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    std::cout << "Linked List Contents: ";
    list.display();
}

void quickSortDemo() {
    std::vector<int> data;
    data.push_back(4);
    data.push_back(2);
    data.push_back(7);
    data.push_back(3);
    data.push_back(1);

    std::cout << "Original Array: ";
    for (std::size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }

    QuickSort::sort(data);

    std::cout << "\nSorted Array: ";
    for (std::size_t i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}


void graphDemo() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    std::cout << "DFS starting from vertex 2: ";
    g.DFS(2);
    std::cout << "BFS starting from vertex 2: ";
    g.BFS(2);
}

void dynamicProgrammingDemo() {
    std::vector<int> weights;
    weights.push_back(10);
    weights.push_back(20);
    weights.push_back(30);

    std::vector<int> values;
    values.push_back(60);
    values.push_back(100);
    values.push_back(120);

    int maxWeight = 50;

    std::cout << "Maximum value in knapsack of weight " << maxWeight << " is: "
              << DynamicProgramming::knapsack(maxWeight, weights, values, values.size()) << std::endl;
}

void matrixOperationsDemo() {
    MatrixOperations::Matrix matA(2, std::vector<double>(2));
    matA[0][0] = 1; matA[0][1] = 2;
    matA[1][0] = 3; matA[1][1] = 4;

    MatrixOperations::Matrix matB(2, std::vector<double>(2));
    matB[0][0] = 5; matB[0][1] = 6;
    matB[1][0] = 7; matB[1][1] = 8;

    MatrixOperations::Matrix matSum = MatrixOperations::add(matA, matB);
    MatrixOperations::Matrix matProduct = MatrixOperations::multiply(matA, matB);
    double detA = MatrixOperations::determinant(matA);

    std::cout << "Sum of A and B: \n";
    for (std::size_t i = 0; i < matSum.size(); i++) {
        for (std::size_t j = 0; j < matSum[i].size(); j++) {
            std::cout << matSum[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Product of A and B: \n";
    for (std::size_t i = 0; i < matProduct.size(); i++) {
        for (std::size_t j = 0; j < matProduct[i].size(); j++) {
            std::cout << matProduct[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Determinant of A: " << detA << std::endl;
}

void machineLearningDemo() {
    MachineLearningBasics::SimpleLinearRegression model;

    // Example data
    std::vector<double> x_values;
    x_values.push_back(1.0); x_values.push_back(2.0); x_values.push_back(3.0);

    std::vector<double> y_values;
    y_values.push_back(2.0); y_values.push_back(4.0); y_values.push_back(6.0);

    // Fit the model to the data
    model.fit(x_values, y_values);

    // Make a prediction
    double x_to_predict = 4.0;
    double predicted_y = model.predict(x_to_predict);

    std::cout << "Predicted y for x = " << x_to_predict << ": " << predicted_y << std::endl;
}

void dataCompressionDemo() {
    std::string originalString = "AAAABBBCCDAA";
    std::cout << "Original String: " << originalString << std::endl;

    // Compress the string
    std::string compressedString = DataCompression::runLengthEncode(originalString);
    std::cout << "Compressed String: " << compressedString << std::endl;

    // Decompress the string
    std::string decompressedString = DataCompression::runLengthDecode(compressedString);
    std::cout << "Decompressed String: " << decompressedString << std::endl;
}

void algorithmicPuzzlesDemo() {
    std::cout << "Tower of Hanoi for 3 disks:\n";
    AlgorithmicPuzzles::towerOfHanoi(3, 'A', 'C', 'B');

    std::cout << "\nN-Queens for 4x4 board:\n";
    AlgorithmicPuzzles::solveNQueens(4);
}
