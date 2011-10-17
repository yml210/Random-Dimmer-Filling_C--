/** random.h
 *  random number generators
 */

#ifndef RANDOM_H
#define RANDOM_H 1
#include <cstdlib>
#include <time.h>
using namespace std;

void random_number_initialization(int seed = 2345)
{ if(seed==0) seed = time(0);
  srand(seed); }

int random_integer_uniform(int min, int max)
{ return min + rand() % (max-min); }

double random_double_uniform(double min, double max)
{ return min + double(rand()%RAND_MAX)/RAND_MAX*(max-min); }

#endif //RANDOM_H
