#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class LogisticRegression {
    public:
        vector<double> weights;
        double bias;
        double learning_rate;
        int num_iterations;

        LogisticRegression(double lr, int iters) {
            learning_rate = lr;
            num_iterations = iters;
        }

        double sigmoid(double z) {
            return 1 / (1 + exp(-z));
        }

        void train(vector<vector<double>> X, vector<double> y) {
            int num_features = X[0].size();
            weights.resize(num_features);
            bias = 0.0;
            for (int i = 0; i < num_features; i++) {
                weights[i] = 0.0;
            }
            for (int i = 0; i < num_iterations; i++) {
                double cost = 0.0;
                vector<double> dw(num_features, 0.0);
                double db = 0.0;
                for (int j = 0; j < X.size(); j++) {
                    double z = bias;
                    for (int k = 0; k < num_features; k++) {
                        z += weights[k] * X[j][k];
                    }
                    double y_hat = sigmoid(z);
                    cost += -(y[j] * log(y_hat) + (1 - y[j]) * log(1 - y_hat));
                    double error = y_hat - y[j];
                    db += error;
                    for (int k = 0; k < num_features; k++) {
                        dw[k] += error * X[j][k];
                    }
                }
                cost /= X.size();
                db /= X.size();
                for (int j = 0; j < num_features; j++) {
                    dw[j] /= X.size();
                    weights[j] -= learning_rate * dw[j];
                }
                bias -= learning_rate * db;
                if (i % 100 == 0) {
                    cout << "Iteration " << i << ", Cost: " << cost << endl;
                }
            }
        }

        vector<double> predict(vector<vector<double>> X) {
            vector<double> y_pred(X.size(), 0.0);
            for (int i = 0; i < X.size(); i++) {
                double z = bias;
                for (int j = 0; j < weights.size(); j++) {
                    z += weights[j] * X[i][j];
                }
                double y_hat = sigmoid(z);
                if (y_hat >= 0.5) {
                    y_pred[i] = 1.0;
                }
            }
            return y_pred;
        }
};

int main() {
    // Verileri tanımlayalım
    vector<double> oda_sayisi = {2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4};
    vector<double> metrekare = {80, 120, 150, 85, 130, 160, 200, 90, 130, 160, 200, 85, 130, 155, 95, 140, 165, 200, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165, 100, 150, 170, 210, 95, 140, 165};
    vector<double> kat = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};

    vector<vector<double>> X = {oda_sayisi, metrekare, kat};
    vector<double> y = {100000, 150000, 200000, 120000, 180000, 250000, 300000, 130000, 190000, 270000, 350000, 120000, 180000, 240000, 140000, 200000, 260000, 320000, 150000, 210000, 280000, 340000, 160000, 220000, 290000, 170000, 230000, 300000, 350000, 180000, 240000, 310000, 190000, 250000, 320000, 200000, 260000, 330000, 210000, 270000, 340000, 220000, 280000, 350000, 230000, 290000, 360000, 240000, 300000, 370000, 250000, 310000, 380000, 260000, 320000, 390000, 270000, 330000, 400000, 280000, 340000, 410000, 290000, 350000, 420000, 300000, 360000, 430000, 310000, 370000, 440000, 320000, 380000, 450000, 330000, 390000, 460000, 340000, 400000, 470000, 350000, 410000, 480000, 360000, 420000, 490000, 370000, 430000, 500000};

    // Özellikleri normalleştirelim
    for (int i = 0; i < X.size(); i++) {
        double mean = 0.0;
        for (int j = 0; j < X[i].size(); j++) {
            mean += X[i][j];
        }
        mean /= X[i].size();
        double std_dev = 0.0;
        for (int j = 0; j < X[i].size(); j++) {
            std_dev += pow(X[i][j] - mean, 2);
        }
        std_dev /= X[i].size();
        std_dev = sqrt(std_dev);
        for (int j = 0; j < X[i].size(); j++) {
            X[i][j] = (X[i][j] - mean) / std_dev;
        }
    }

    // Modeli eğitelim
    LogisticRegression lr(0.01, 1000);
    lr.train(X, y);

    // Test verileri oluşturalım
    vector<vector<double>> X_test = {{3, 120, 2}, {4, 150, 3}, {5, 200, 4}};

    // Test verilerini normalleştirelim
    for (int i = 0; i < X_test.size(); i++) {
        for (int j = 0; j < X_test[i].size(); j++) {
            X_test[i][j] = (X_test[i][j] - mean) / std_dev;
        }
    }

    // Tahminlerimizi yapalım
    vector<double> y_pred = lr.predict(X_test);

    // Tahmin sonuçlarını yazdıralım
    for (int i = 0; i < y_pred.size(); i++) {
        cout << "Tahmin " << i+1 << ": " << y_pred[i] << endl;
    }

    return 0;
}