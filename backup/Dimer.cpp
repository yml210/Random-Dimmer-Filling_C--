#include "Dimer.h"

Dimer::Dimer(Site& head, Site& tail)
{ _position.push_back(&head);
  _position.push_back(&tail);
  vector<Site*>& nbs_head = head.get_neighbours();
  vector<Site*>& nbs_tail = head.get_neighbours();
  set_union(nbs_head.begin(),nbs_head.end(),nbs_tail.begin(),
    nbs_tail.end(), _neighbouring_sites.begin());
}

int Dimer::num_neighbouring_sites()
{ return _neighbouring_sites.size();}

Site& Dimer::get_neighbouring_site(int i)
{ return *(_neighbouring_sites[i]);}

void Dimer::draw(ostream& out) const
{ Site::Orientation& ort_head = _position[0]->get_Orientation();
  Site::Orientation& ort_tail = _position[1]->get_Orientation();
  out << ort_head[0] << " " << ort_head[1] << " " << ort_tail[0]
    << ort_tail[1];
}

