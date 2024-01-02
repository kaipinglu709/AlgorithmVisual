// Dynamic_Programming.hpp

#pragma once
#include <vector>
#include <algorithm>

class DynamicProgramming {
public:
    // Fibonacci Sequence with Memoization
    static int fibonacci(int n) {
        static std::vector<int> memo;
        if (memo.empty()) {
            memo.push_back(0); // First Fibonacci number
            memo.push_back(1); // Second Fibonacci number
        }

        if (n < static_cast<int>(memo.size())) return memo[n];

        for (int i = memo.size(); i <= n; ++i) {
            memo.push_back(memo[i - 1] + memo[i - 2]);
        }
        return memo[n];
    }

    // 0/1 Knapsack Problem
    static int knapsack(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
        std::vector<std::vector<int> > dp(n + 1, std::vector<int>(W + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int w = 1; w <= W; ++w) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = std::max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
};

