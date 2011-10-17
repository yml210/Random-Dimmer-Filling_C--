#include "Dimer.h"
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

Dimer::Dimer(Site& head, Site& tail)
{ _position.push_back(&head);
  _position.push_back(&tail);
  vector<Site*>& nbs_head = head.get_neighbours();
  vector<Site*>& nbs_tail = tail.get_neighbours();
  
  set<Site*> set1(nbs_head.begin(),nbs_head.end());
  set1.insert(nbs_tail.begin(),nbs_tail.end());
  
  set1.erase(&head);
  set1.erase(&tail);

  set<Site*>::iterator itr = set1.begin();
  while(itr != set1.end()){
    _neighbouring_sites.push_back(*itr);
    itr++;
  }
}

int Dimer::num_neighbouring_sites()
{ return _neighbouring_sites.size();}

Site& Dimer::get_neighbouring_site(int i)
{ return *(_neighbouring_sites[i]);}

void Dimer::draw(ostream& out) const
{ Site::Orientation& ort_head = _position[0]->get_Orientation();
  Site::Orientation& ort_tail = _position[1]->get_Orientation();
  out << ort_head[0] << " " << ort_head[1] << " " << ort_tail[0]
    <<" " << ort_tail[1];
}

