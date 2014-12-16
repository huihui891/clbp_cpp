#include "util.h"

bool util::almost_equal(const uvec &v1, const uvec &v2, double epsilon) {
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

bool util::almost_equal(const mat &v1, const mat &v2, double epsilon) {
    if (v1.n_rows != v2.n_rows || v1.n_cols != v2.n_cols) {
        cout << "Invalid sizes: (" <<  v1.n_rows << ", " << v1.n_cols << "), (" << v2.n_rows << ", " << v2.n_cols << ")"<< endl;
        return false;
    }

    for (uword i = 0; i < v1.n_rows; i++) {
        for (uword j = 0; j < v1.n_cols; j++) {
            if (abs(v1(i,j) - v2(i,j)) > epsilon) {
                cout << "Vectors differ at position " << i << ", " << j << "; V1: " << v1(i,j) << "; V2: " << v2(i,j) << endl;
                return false;
            }
        }
    }

    return true;

}


bool util::almost_equal(const umat &v1, const umat &v2, double epsilon) {
    if (v1.n_rows != v2.n_rows || v1.n_cols != v2.n_cols) {
        cout << "Invalid sizes: (" <<  v1.n_rows << ", " << v1.n_cols << "), (" << v2.n_rows << ", " << v2.n_cols << ")"<< endl;
        return false;
    }

    for (uword i = 0; i < v1.n_rows; i++) {
        for (uword j = 0; j < v1.n_cols; j++) {
            if (abs(v1(i,j) - v2(i,j)) > epsilon) {
                cout << "Vectors differ at position " << i << ", " << j << "; V1: " << v1(i,j) << "; V2: " << v2(i,j) << endl;
                return false;
            }
        }
    }

    return true;

}
