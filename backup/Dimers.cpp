#include "Dimers.h"
#include "Lattice.cpp"
#include "Random.h"

Dimers::Dimers(Lattice& lt)
{ random_number_initialization();
  initialize_accessible_sites(lt);
}

inline void Dimers::initialize_accessible_sites(Lattice& lt)
{ set<Site*>::iterator itr = _accessible_sites.begin();
  for(int x = 0; x < lt.dim1(); x++)
  { for(int y= 0; y < lt.dim2(); y++)
    { _accessible_sites.insert(itr, lt.get_site_pointer(x,y));
      itr++;
    }
  }
}

bool  Dimers::drop_dimer()
{
  int nas = _accessible_sites.size();
  if(nas==0) return false;

// from the list of accessible sites, randomly select a head site for the dimer.
  int nshift = random_integer_uniform(0, nas);
  set<Site*>::iterator itr = _accessible_sites.begin();
  for( int i = 1; i <= nshift; i++)  itr=itr++;
  Site* pHead_site = *itr;
  pHead_site->set_occupied();

// in the unoccupied neighbours of the hear site, randomly select the tail 
// site for the dimer.
  int nun = pHead_site->num_unoccupied_neighbours();
  int ntail = random_integer_uniform(0, nun);
  Site* pTail_site = pHead_site->get_unoccupied_neighbour(ntail);
  pTail_site->set_occupied();

// erase the pair site from accessible list.
  _accessible_sites.erase(itr);
  itr = _accessible_sites.find(pTail_site);
  _accessible_sites.erase(itr);


// Create a dimer at the selected site.
  Dimer* dm = new Dimer(*pHead_site, *pTail_site);
  _dimers.push_front(dm);

// Erase the neighbourless site from the list of accessible sites
  for(int i=1; i<dm->num_neighbouring_sites();i++)
  { Site& s = dm->get_neighbouring_site(i);
    if(s.num_unoccupied_neighbours()==0)
    { itr = _accessible_sites.find(&s);
      _accessible_sites.erase(itr);
    }
  }

  return true;
}

void Dimers::draw(ostream& out)
{ out << "Total number of Dimers: " << _dimers.size() << endl<<endl;
  list<Dimer*>::iterator itr = _dimers.begin();
  while(itr != _dimers.end())
  { (*itr)->draw(out);
    out << endl;
  }
}




