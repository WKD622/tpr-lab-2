#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

long double R_PI = 3.14159265358979323L;

double rand_value(double start, double end)
{
    return (double)rand() / RAND_MAX * (end - start) + start;
}

double monte_carlo(unsigned long long int number_of_shoots, double x_start, double x_end, double y_start, double y_end)
{
    int success = 0;
    int loss = 0;
    long long int circle_points = 0;
    double rand_x, rand_y, origin_dist;
    unsigned long long int i = 0;
    for (i = 0; i < number_of_shoots; i++)
    {
        rand_x = (double)(rand() / ((double)RAND_MAX));
        rand_y = (double)(rand() / ((double)RAND_MAX));

        origin_dist = rand_x * rand_x + rand_y * rand_y;

        if (origin_dist <= 1)
            success++;
        else {
            loss++;
        }
    }
    return ((double)success / ((double)loss + (double)success)) * (x_end - x_start) * (y_end - y_start);
}

int main(int argc, char **argv)
{
    int number_of_tries = strtoll(argv[2], NULL, 0);
    int i;
    for (i = 0; i < number_of_tries; i++)
    {
        srand(time(NULL));
        struct timeval tval_before, tval_after, tval_result;
        gettimeofday(&tval_before, NULL);
        unsigned long long int number_of_shoots = strtoll(argv[1], NULL, 0);
        double area_size = monte_carlo(number_of_shoots, 0.0, 1.0, 0.0, 1.0);
        double pi = 4 * area_size;
        gettimeofday(&tval_after, NULL);
        timersub(&tval_after, &tval_before, &tval_result);
        long double time_passed_in_seconds = (long double)tval_result.tv_sec + (long double)tval_result.tv_usec / 1000000;
        printf("pi: %f\n", pi);
        printf("time passed: %Lf\n", time_passed_in_seconds);
        printf("pi dif: %.14Lf\n", fabsl(R_PI - pi));
        return 0;
    }
}
