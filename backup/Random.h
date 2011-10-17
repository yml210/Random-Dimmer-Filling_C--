/** random.h
 *  random number generators
 */

#ifndef RANDOM_H
#define RANDOM_H 1
#include <cstdlib>
using namespace std;

void random_number_initialization()
{ srand(100);}

int random_integer_uniform(int min, int max)
{ return min + rand()*(max-min)/RAND_MAX; }

double random_double_uniform(double min, double max)
{ return min + (max-min)*rand()/RAND_MAX; }

#endif //RANDOM_H
