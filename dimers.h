/** Dimers.h
 * Dimers class
 */

#ifndef DIMERS_H
#define DIMERS_H 1
#include <set>
#include <list>
#include <ostream>
#include "Site.h"
#include "Lattice.h"
#include "Dimer.h"
#include "Random.h"
using namespace std;

class Dimers
{ set<Site*> _accessible_sites;
  list<Dimer*> _dimers;
  
public:
  Dimers()
  { random_number_initialization();}

  void initialize_accessible_sites(Lattice& lt)
  { set<Site*>::iterator itr = _accessible_sites.begin();
    for(int x = 0; x < lt.dim1(); x++)
    { for(int y= 0; y < lt.dim2(); y++)
      { _accessible_sites.insert(itr, lt.get_site_pointer(x,y));
        itr++;
      }
    }
    int nas = _accessible_sites.size();
  }

  bool  drop_dimer()
  { 
    int nas = _accessible_sites.size();
    if(nas==0) return false;

    int nshift = random_integer_uniform(0, nas);
    set<Site*>::iterator itr = _accessible_sites.begin();
    for( int i = 1; i <= nshift; i++)  itr=itr++;
    Site* pHead_site = *itr;

    int nun = pHead_site->num_unoccupied_neighbours();
    int ntail = random_integer_uniform(0, nun);
    Site* pTail_site = pHead_site->get_neighbour(ntail);

    _accessible_sites.erase(itr);
    itr = _accessible_sites.find(pTail_site);
    _accessible_sites.erase(itr);

    pHead_site->set_occupied();
    pTail_site->set_occupied();

    Dimer* dm = new Dimer(*pHead_site, *pTail_site);
    _dimers.push_front(dm);
 
   
    for(int i=1; i<dm->num_neighbouring_sites();i++)
    { Site& s = dm->get_neighbouring_site(i);
      if(s.num_unoccupied_neighbours()==0)
      { itr = _accessible_sites.find(&s);
        _accessible_sites.erase(itr);
      }
    }

    return true;
  }
    
  void draw(ostream& out)
  { out << "Total number of Dimers: " << _dimers.size() << endl<<endl;
    list<Dimer*>::iterator itr = _dimers.begin();
    while(itr != _dimers.end())
    { (*itr)->draw(out);
      out << endl;
    }
  }
 
   

};
#endif //DIMERS_H
