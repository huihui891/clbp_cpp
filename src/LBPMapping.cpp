#include "LBPMapping.h"

using namespace arma;

LBPMapping::LBPMapping()
{
}

LBPMapping::~LBPMapping()
{
}

int countBits(int number) {
    int count = 0;

    while (number != 0) {
        count += number & 1;
        number = number >> 1;
    }
    return count;
}

/* Generates the LBP mappings for Uniform and Rotation-invariant (RIU2)*/
MappingTable LBPMapping::GetMapping_RIU2(int NumberOfPoints) {
    int table_size = 1 << NumberOfPoints; // 2^NumberOfPoints

    uvec result(table_size);

    //Creates a mask to ensure that mappings don't exceed "NumberOfPoints" bits
    int mask = 0;
    for (int i=0; i < NumberOfPoints; i++) {
        mask  = mask | 1 << i;
    }

    for (int i=0; i < table_size; i++) {
        int bitget = (i >> (NumberOfPoints-1)) & 1;
        int j = ((i << 1) & mask) | bitget;

        int numt = countBits(i ^ j);

        if (numt <= 2)
            result(i) = countBits(i);
        else
            result(i) = NumberOfPoints + 1;

    }

    MappingTable m;
    m.numBins = NumberOfPoints + 2;
    m.numSamples = NumberOfPoints;
    m.table = std::move(result);
    return std::move(m);
}
