#include "UnitTest++.h"
#include "LBPMapping.h"
#include <armadillo>
#include "util.h"

using namespace arma;
using namespace std;

namespace {

TEST(TestRotationUniformMapping_RIU2) {
    LBPMapping mapping;

    uvec actual_4 = mapping.GetMapping_RIU2(4);
    uvec expected_4;
    expected_4.load("test/map_4.mat");

    CHECK(util::almost_equal(actual_4, expected_4));

    uvec actual_10 = mapping.GetMapping_RIU2(10);
    uvec expected_10;
    expected_10.load("test/map_10.mat");

    CHECK(util::almost_equal(actual_10, expected_10));

    uvec actual_24 = mapping.GetMapping_RIU2(24);
    uvec expected_24;
    expected_24.load("test/map_24.mat");

    CHECK(util::almost_equal(actual_24, expected_24));


    CHECK_EQUAL(true, true);
}

}
