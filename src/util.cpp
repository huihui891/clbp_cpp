#include "util.h"

bool util::almost_equal(uvec v1, uvec v2, double epsilon) {
    if (v1.n_rows != v2.n_rows) {
        cout << "Invalid sizes: " <<  v1.n_rows << ", " << v2.n_rows<< endl;
        return false;
    }

    for (uword i = 0; i < v1.n_rows; i++) {
        if (abs(v1(i) - v2(i)) > epsilon) {
            cout << "Vectors differ at position " << i << "; V1: " << v1(i) << "; V2: " << v2(i) << endl;
            return false;
        }
    }

    return true;

}
