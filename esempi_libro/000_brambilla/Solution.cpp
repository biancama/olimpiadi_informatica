#include <algorithm>

int best_city(const int biglietti[], const int abitanti[], int n) {
    int *clockwise, *counter_clockwise, *costs_for_city;

    clockwise = new int[n];
    counter_clockwise = new int[n];
    costs_for_city = new int[n]{0};

    for(int i = 0; i < n ; i++) {
        clockwise[i] = 0;
        for (int j = 1; j < n; ++j) {
            clockwise[(j+i) %n] = clockwise[(j + i - 1) % n] + biglietti[(j + i - 1) % n];
        }
        counter_clockwise[i] = 0;
        for (int j = 1; j < n; ++j) {
            counter_clockwise[(n - j + i) % n] = counter_clockwise[(n - j + i + 1) % n] + biglietti[(n - j + i) % n];
        }
        for (int j = 0; j < n; ++j) {
            costs_for_city[j] += std::min(clockwise[j], counter_clockwise[j])*abitanti[i];
        }
    }
    int min_cost = costs_for_city[0];
    int result = 1;
    for(int i = 1; i < n ; i++) {
       if (costs_for_city[i] < min_cost) {
           min_cost = costs_for_city[i];
           result = i +1;
       }
    }
    delete[] clockwise;
    delete[] counter_clockwise;
    delete[] costs_for_city;
    return result;
}