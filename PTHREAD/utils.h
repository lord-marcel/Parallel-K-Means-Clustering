#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <math.h>
#include <pthread.h>


struct point {
    int dimensions;
    double* coordinates;
    int cluster;
    double distance_from_centroid;
};

struct centroid {
    struct point centroid;
    struct point accumulator;
    int points_in_cluster;
};

struct space {
    struct point* points;
    struct centroid* centroids;
    int number_of_points;
    int dimensions;
    int clusters;
};

int equal(struct point p1, struct point p2, int dimensions);
double euclidean(struct point p1, struct point p2, int dimensions);
void add(struct point p1, struct point p2, int dimensions);
void subtract(struct point p1, struct point p2, int dimensions);
void space_init(struct space* sp, int points, int dimensions, int clusters);
void space_free(struct space* sp, int points, int dimensions, int clusters);

#endif