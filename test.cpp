#include "Random.h"
#include <iostream>
using namespace std;

int main()
{
  random_number_initialization();
  std::cout << random_integer_uniform(1,10)<< std::endl
	    << random_double_uniform(0.0, 1.0)<< endl;
  return 0;
}

