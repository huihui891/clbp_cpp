#ifndef UTIL_H
#define UTIL_H

#include <armadillo>

using namespace arma;

class util
{
    public:
        static bool almost_equal(const uvec &v1, const uvec &v2, double epsilon=1e-6);
        static bool almost_equal(const mat &v1, const mat &v2, double epsilon=1e-6);
        static bool almost_equal(const umat &v1, const umat &v2, double epsilon=1e-6);
    protected:
    private:
};

#endif // UTIL_H
