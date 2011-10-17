#include <iostream>
#include <fstream>
#include "Site.h"
#include "Lattice.cpp"
#include "Dimers.h"
using namespace std;

int main()
{ 
  int N;
  cout << "Please input the size of lattice (N): \n";
  cin >> N;

  Site* sp;

  Lattice lt(N,N);

  Dimers dms(lt);
  int time = 0;
  while(dms.drop_dimer()){ time++;}

  cout << endl;
  cout << "The final distribution of pair (x1,y1) and (x2, y2) is \n";
	 
  cout << "given in the file dist.dat. The format is \"x1 y1 x2 y2\".\n";
  ofstream outfile("dist.dat");
  dms.draw(outfile);

  int nos=dms.num_occupied_sites();
  cout << endl;
  cout << "Total number of sites: "<< N*N<< endl;
  cout << "the number of occupied sites: "<< nos << endl;
  cout << "occupancy: "<< double(nos)/N/N << endl;

  return 0;
}
