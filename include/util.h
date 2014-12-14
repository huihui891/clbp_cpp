#ifndef UTIL_H
#define UTIL_H

#include <armadillo>

using namespace arma;

class util
{
    public:
        static bool almost_equal(uvec v1, uvec v2, double epsilon=1e-6);
    protected:
    private:
};

#endif // UTIL_H
