
#include "UnitTest++.h"
#include "CLBP.h"
#include <armadillo>
#include "util.h"

using namespace arma;
using namespace std;

namespace {

TEST(TestGetPoints) {
    CLBP target;

    mat result_8 = target.GetPointsToBeEvaluated(8,1);
    mat expected_8;
    expected_8.load("test/points_8_1.mat");
    CHECK(util::almost_equal(result_8, expected_8));

    mat result_16 = target.GetPointsToBeEvaluated(16,2);
    mat expected_16;
    expected_16.load("test/points_16_2.mat");
    CHECK(util::almost_equal(result_16, expected_16));

    mat result_24 = target.GetPointsToBeEvaluated(24,3);
    mat expected_24;
    expected_24.load("test/points_24_3.mat");
    CHECK(util::almost_equal(result_24, expected_24));
}

TEST(TestCBLP) {
    CLBP target;
    LBPMapping mapping;

    mat img;
    img.load("test/img_norm.mat");

    CLBP_Codes result = target.Run(img, 1, 8, mapping.GetMapping_RIU2(8));
    umat expected_clbp_c, expected_clbp_s, expected_clbp_m;
    expected_clbp_c.load("test/clbp_c.mat");
    expected_clbp_s.load("test/clbp_s.mat");
    expected_clbp_m.load("test/clbp_m.mat");

    CHECK(util::almost_equal(result.CLBP_C, expected_clbp_c));
    CHECK(util::almost_equal(result.CLBP_S, expected_clbp_s));
    CHECK(util::almost_equal(result.CLBP_M, expected_clbp_m));
}


}
