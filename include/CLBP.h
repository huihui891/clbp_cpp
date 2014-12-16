#ifndef CLBP_H
#define CLBP_H

#include <armadillo>
#include "LBPMapping.h"

using namespace arma;

struct CLBP_Codes {
    umat CLBP_S;
    umat CLBP_M;
    umat CLBP_C;
};

class CLBP
{
    public:
        CLBP();
        virtual ~CLBP();

        CLBP_Codes Run(mat image, double radius, int neighbors, MappingTable mapping);

        mat GetPointsToBeEvaluated(int neighbors, double radius);

    protected:
    private:
};

#endif // CLBP_H
