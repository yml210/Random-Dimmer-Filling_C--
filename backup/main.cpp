#include <iostream>
//#include <fostream>
#include "Site.h"
#include "Lattice.cpp"
#include "Dimers.h"
using namespace std;

int main()
{ 
  int N;
  cout << "Please input the size of lattice (N): \n";
//  cin >> N;

  N = 4;

  Site* sp;

  Lattice lt(N,N);
  sp=lt(0,0);
  Site::Orientation& ort = sp->get_Orientation();

  cout << sp->num_neighbours() << endl;
  cout << sp->num_unoccupied_neighbours() << endl;
  cout << ort[0]<<" "<<ort[1]<<endl;
//  cout << lt.dim1()<<" "<<lt.dim2()<<endl;
  exit(1);

  Dimers dms(lt);
  int time = 0;
  while(dms.drop_dimer() & time < 10)
  { time ++;}

  
//  dms.draw(cout);

  return 0;
}
