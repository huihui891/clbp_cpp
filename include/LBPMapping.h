#ifndef LBPMAPPING_H
#define LBPMAPPING_H

#include <armadillo>

using namespace arma;

struct MappingTable
{
    uvec table;
    int numBins;
    int numSamples;
};

class LBPMapping
{
    public:
        LBPMapping();

        MappingTable GetMapping_RIU2(int NumberOfPoints);
        virtual ~LBPMapping();
    protected:
    private:
};

#endif // LBPMAPPING_H
