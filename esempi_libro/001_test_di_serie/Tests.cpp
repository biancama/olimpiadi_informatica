#include "../../catch.hpp"
#include <vector>
int respect_algo(int K, int N, const std::vector<int> & strength);
TEST_CASE("teste di serie 01" ) {
    int K = 3;
    int N = 4;

    std::vector<int> strength = {5,7,9,3,6,78,90,43,78,71,32};

    REQUIRE(respect_algo(K, N,strength)== 0);
}

TEST_CASE("teste di serie 02" ) {
    int K = 3;
    int N = 4;

    std::vector<int> strength = {2,2,2,1,2,1,3,1,2,4,2,1};

    REQUIRE(respect_algo(K, N,strength)== 1);
}
