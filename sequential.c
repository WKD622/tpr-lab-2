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

double x_2(double x)
{
    return pow(x, 2.0);
}

double monte_carlo(unsigned long long int number_of_shoots, double x_start, double x_end, double y_start, double y_end)
{
    int success = 0;
    int loss = 0;
    unsigned long long int i = 0;
    for (i = 0; i < number_of_shoots; i++)
    {
        double x = rand_value(x_start, x_end);
        double y = rand_value(y_start, y_end);

        double x_pow_value = x_2(x);
        double y_pow_value = x_2(y);
        double sum = x_pow_value + y_pow_value;
        if (sum <= 1)
            success++;
        else
            loss++;
    }
    return ((double)success / ((double)loss + (double)success)) * (x_end - x_start) * (y_end - y_start);
}

int main(int argc, char** argv)
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
    printf("PI: %f\n", pi);
    printf("TIME: %Lf\n", time_passed_in_seconds);
    printf("DIF: %.14Lf\n", fabsl(R_PI - pi));
    return 0;
}
