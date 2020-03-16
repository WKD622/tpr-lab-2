#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
    for (unsigned long long int i = 0; i < number_of_shoots; i++)
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

int main(){
    unsigned long long int number_of_shoots = 10000000;
    double area_size = monte_carlo(number_of_shoots, 0.0, 1.0, 0.0, 1.0); 
    printf("%f\n", 4 * area_size);
    return 0;
}

