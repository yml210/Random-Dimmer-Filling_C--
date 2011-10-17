/** Dimers.h
 * Dimers class
 */

#ifndef DIMERS_H
#define DIMERS_H 1
#include <set>
#include <list>
#include <ostream>
#include "Lattice.h"
#include "Dimer.h"
using namespace std;

class Dimers
{ set<Site*> _accessible_sites;
  list<Dimer*> _dimers;
  
public:
  Dimers(){};
  Dimers(Lattice& lt);

  void initialize_accessible_sites(Lattice& lt);

  bool  drop_dimer();
    
  void draw(ostream& out);

};
#endif //DIMERS_H
