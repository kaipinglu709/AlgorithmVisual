// MachineLearningBasics.hpp

#pragma once
#include <vector>
#include <cmath>  // For sqrt and pow functions
#include <stdexcept>  // For std::invalid_argument

class MachineLearningBasics {
public:
    class SimpleLinearRegression {
    private:
        double slope;
        double intercept;

    public:
        SimpleLinearRegression() : slope(0.0), intercept(0.0) {}

        // Fit the model to the data (x_values and y_values)
        void fit(const std::vector<double>& x_values, const std::vector<double>& y_values) {
            if (x_values.size() != y_values.size()) {
                throw std::invalid_argument("Size of x_values and y_values must be the same");
            }

            size_t n = x_values.size();
            double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0;

            for (size_t i = 0; i < n; ++i) {
                sum_x += x_values[i];
                sum_y += y_values[i];
                sum_xy += x_values[i] * y_values[i];
                sum_x2 += x_values[i] * x_values[i];
            }

            double x_mean = sum_x / n;
            double y_mean = sum_y / n;

            slope = (sum_xy - n * x_mean * y_mean) / (sum_x2 - n * x_mean * x_mean);
            intercept = y_mean - slope * x_mean;
        }

        // Predict the y value for a given x value
        double predict(double x) const {
            return slope * x + intercept;
        }

        // Getters for slope and intercept
        double getSlope() const { return slope; }
        double getIntercept() const { return intercept; }
    };
};
