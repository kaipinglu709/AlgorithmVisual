// Algorithmic_Puzzles.hpp

#pragma once
#include <iostream>
#include <vector>

class AlgorithmicPuzzles {
public:
    // Tower of Hanoi
    static void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
        if (n == 1) {
            std::cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << std::endl;
            return;
        }
        towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
        std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << std::endl;
        towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    }

    // N-Queens Problem
    static bool solveNQueens(int n) {
        std::vector<int> position(n, -1);
        return placeQueens(position, 0, n);
    }

private:
    static bool isSafe(const std::vector<int>& position, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (position[i] == col || position[i] - i == col - row || position[i] + i == col + row) {
                return false;
            }
        }
        return true;
    }

    static bool placeQueens(std::vector<int>& position, int row, int n) {
        if (row == n) {
            printQueens(position, n);
            return true;
        }

        bool result = false;
        for (int col = 0; col < n; ++col) {
            if (isSafe(position, row, col)) {
                position[row] = col;
                result = placeQueens(position, row + 1, n) || result;
                position[row] = -1; // Backtrack
            }
        }

        return result;
    }

    static void printQueens(const std::vector<int>& position, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << (position[i] == j ? "Q " : "_ ");
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};
