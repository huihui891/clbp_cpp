#ifndef LBPMAPPING_H
#define LBPMAPPING_H

#include <armadillo>

using namespace arma;

class LBPMapping
{
    public:
        LBPMapping();

        uvec GetMapping_RIU2(int NumberOfPoints);
        virtual ~LBPMapping();
    protected:
    private:
};

#endif // LBPMAPPING_H
