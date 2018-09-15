#include "../../catch.hpp"
int best_city(const int biglietti[], const int abitanti[], int n);

TEST_CASE("Brambilla test case 01" ) {
    int  n = 4;
    int biglietti[] = {45, 34, 18, 40};
    int abitanti[] = {3, 0, 4, 2};

   REQUIRE(best_city(biglietti, abitanti, n));
}

