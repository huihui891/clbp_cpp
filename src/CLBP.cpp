#include "CLBP.h"
#include <iostream>
#include <armadillo>

using namespace arma;

CLBP::CLBP()
{
    //ctor
}

CLBP::~CLBP()
{
    //dtor
}

template<class Matrix>
void print_matrix(Matrix matrix) {
    matrix.print(std::cout);
}

template void print_matrix<mat>(mat matrix);
template void print_matrix<umat>(umat matrix);

mat GetPointsWithDistance(const mat& img, double y, double x, double dy, double dx) {
    double fy = floor(y);
    double cy = ceil(y);
    int ry = round(y);

    double fx = floor(x);
    double cx = ceil(x);
    int rx = round(x);

    mat N;

    if (std::abs(x - rx) < 1e-6 && std::abs(y - ry) < 1e-6) {
        N = img.submat(ry, rx, ry + dy, rx + dx);
    }
    else { //Need interpolation
        double ty = y - fy;
        double tx = x - fx;

        // Calculate the interpolation weights.
        double w1 = (1 - tx) * (1 - ty);
        double w2 =      tx  * (1 - ty);
        double w3 = (1 - tx) *      ty ;
        double w4 =      tx  *      ty ;

        // Compute interpolated pixel values
        N = w1 * img.submat(fy, fx, fy + dy, fx + dx)
          + w2 * img.submat(fy, cx, fy + dy, cx + dx)
          + w3 * img.submat(cy, fx, cy + dy, fx + dx)
          + w4 * img.submat(cy, cx, cy + dy, cx + dx);
    }
    return std::move(N);
}

CLBP_Codes CLBP::Run(mat image, double radius, int neighbors, MappingTable mapping) {
    CLBP_Codes result;

    mat spoints = GetPointsToBeEvaluated(neighbors, radius);

    int ysize = image.n_rows;
    int xsize = image.n_cols;

    int miny = spoints.col(0).min();
    int maxy = spoints.col(0).max();
    int minx = spoints.col(1).min();
    int maxx = spoints.col(1).max();

    // Block size, each LBP code is computed within a block of size bsizey*bsizex
    int bsizey=ceil(std::max(maxy,0))-floor(std::min(miny,0))+1;
    int bsizex=ceil(std::max(maxx,0))-floor(std::min(minx,0))+1;

    // Coordinates of origin (0,0) in the block
    int origy=-floor(std::min(miny,0));
    int origx=-floor(std::min(minx,0));

    // Calculate dx and dy;
    int dx = xsize - bsizex;
    int dy = ysize - bsizey;

    // Fill the center pixel matrix C.
    mat d_C = image.submat(origy, origx, origy + dy, origx + dx);

    ucube D(dy + 1, dx + 1, neighbors);
    cube Diff(dy + 1, dx + 1, neighbors);
    vec MeanDiff(neighbors);

    for (int i=0; i<neighbors; i++) {
        double y = spoints(i,0) + origy;
        double x = spoints(i,1) + origx;

        mat N = GetPointsWithDistance(image, y, x, dy, dx);

        D.slice(i) = (N >= d_C);

        Diff.slice(i) = abs(N - d_C);
        MeanDiff(i) = mean(mean(Diff.slice(i)));
    }

    double DiffThreshold = mean(MeanDiff);

    result.CLBP_S = umat(dy + 1, dx + 1, fill::zeros);
    result.CLBP_M = umat(dy + 1, dx + 1, fill::zeros);

    result.CLBP_C = umat(dy + 1, dx + 1);

    result.CLBP_C = (d_C >= mean(mean(d_C)));

    for (int i=0; i<neighbors; i++) {
        int v = 1 << i; // 2^i

        result.CLBP_S += v * D.slice(i);

        result.CLBP_M += v * (Diff.slice(i) >= DiffThreshold);
    }

    return std::move(result);
}

mat CLBP::GetPointsToBeEvaluated(int neighbors, double radius) {
    mat result(neighbors, 2);

    double angle_step = 2 * datum::pi / neighbors;

    for (int i = 0; i < neighbors; i++) {
        result(i,0) = -radius * sin(i * angle_step);
        result(i,1) = radius * cos(i * angle_step);
    }

    return std::move(result);
}
