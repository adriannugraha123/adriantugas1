#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

int main() {
    // Menyimpan nilai-nilai mahasiswa
    std::vector<int> nilai = { 92, 65, 74, 80, 80, 70, 78 };

    // Hitung mean
    double mean = static_cast<double>(std::accumulate(nilai.begin(), nilai.end(), 0)) / nilai.size();

    // Hitung median
    std::sort(nilai.begin(), nilai.end());
    double median;
    if (nilai.size() % 2 == 0) {
        median = static_cast<double>(nilai[nilai.size() / 2 - 1] + nilai[nilai.size() / 2]) / 2;
    }
    else {
        median = nilai[nilai.size() / 2];
    }

    // Hitung standard deviasi
    double sum_squared_diff = std::accumulate(nilai.begin(), nilai.end(), 0.0, [mean](double acc, int x) {
        return acc + std::pow(x - mean, 2);
        });
    double std_dev = std::sqrt(sum_squared_diff / nilai.size());

    // Tampilkan hasil
    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Standard Deviasi: " << std_dev << std::endl;

}