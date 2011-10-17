/** Dimer.h
 * Dimer class
 */

#ifndef DIMER_H
#define DIMER_H 1
#include <ostream>
#include <algorithm>
#include <vector>
#include "Site.h"

using namespace std;

class Dimer
{
  vector<Site*> _position;
  vector<Site*> _neighbouring_sites;

public:
  Dimer(Site& head, Site& tail);

  int num_neighbouring_sites();

  Site& get_neighbouring_site(int i);

  void draw(ostream& out) const;
};
#endif //DIMER_H
