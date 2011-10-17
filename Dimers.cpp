#include "Dimers.h"
#include "Lattice.cpp"
#include "Random.h"
#include <iostream>
#include <fstream>

Dimers::Dimers(Lattice& lt)
{ random_number_initialization(0);
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

int Dimers::num_occupied_sites()
{ return _dimers.size()*2;}

bool  Dimers::drop_dimer()
{
  int nas = _accessible_sites.size();
  if(nas==0) return false;
  
// from the list of accessible sites, randomly select a head site for the dimer.
  int nshift = random_integer_uniform(0, nas);
  set<Site*>::iterator itr = _accessible_sites.begin();

  int i=0;
  for( ;itr != _accessible_sites.end();++itr)
  { if( i == nshift)
    { break; }
    else
    { i++; }
  } 
  if(i!=nshift){
    cout << endl;
    cout << i << " " << nshift << " "<<_accessible_sites.size()<<"?"<<endl;
    return false;
  }
  Site* pHead_site = *itr;
  pHead_site->set_occupied();

// in the unoccupied neighbours of the hear site, randomly select the tail 
// site for the dimer.
  int nun = pHead_site->num_unoccupied_neighbours();
  int ntail = 0;
  if(nun > 0) ntail = random_integer_uniform(0, nun);

   
//  Site* pTail_site = pHead_site->get_neighbour(3);
  Site* pTail_site = pHead_site->get_unoccupied_neighbour(ntail);
  vector<Site*>& tn = pTail_site->get_neighbours();
  Site::Orientation& ort= pTail_site->get_Orientation();

  pTail_site->set_occupied();

// erase the pair site from accessible list.
  _accessible_sites.erase(pHead_site);
  _accessible_sites.erase(pTail_site);


// Create a dimer at the selected site.
  Dimer* dm = new Dimer(*pHead_site, *pTail_site);
  _dimers.push_front(dm);

  
// Erase the neighbourless site from the list of accessible sites
  for(int i=0; i< (dm->num_neighbouring_sites()); i++)
  { Site& s = dm->get_neighbouring_site(i);
    if(s.num_unoccupied_neighbours()==0)
    { _accessible_sites.erase(&s); }
  }

  return true;
}

void Dimers::draw(ostream& out)
{ out << "Total number of Dimers: " << _dimers.size() << endl<<endl;
  list<Dimer*>::iterator itr = _dimers.begin();
  while(itr != _dimers.end())
  { (*itr)->draw(out);
    out << endl;
    itr++;
  }
}




