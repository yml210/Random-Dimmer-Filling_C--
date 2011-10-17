/** Dimers.h
 * Dimers class
 */

#ifndef DIMERS_H
#define DIMERS_H 1
#include <set>
#include <list>
#include "Lattice.h"
#include "Dimer.h"
using namespace std;

class Dimers
{ set<Site*> _accessible_sites;
  list<Dimer*> _dimers;
  
public:
  Dimers(){};
  Dimers(Lattice& lt);


  bool  drop_dimer();
  int num_occupied_sites();
  void draw(ostream& out);
private:
  void initialize_accessible_sites(Lattice& lt);

};
#endif //DIMERS_H
