/** Site.cpp
 *
 */

#include "Site.h"

  Site::Site(Orientation& ort)
  { _fOccupied = false;
    set_Orientation(ort);
  }

  Site::Site(const int x, const int y)
  { _fOccupied = false;
    set_Orientation(x,y);
  }

  Site::Orientation& Site::get_Orientation()
  { return _orientation;}

  void Site::set_Orientation(int x, int y)
  { Orientation ort;
    ort[0] = x;
    ort[1] = y;
    set_Orientation(ort);
  }

  bool Site::occupied(){ return _fOccupied;}
  bool Site::unoccupied(){ return !_fOccupied;}

  void Site::set_occupied()
  { _fOccupied = true;
    for(int i=0; i<4; i++)
    { _neighbours[i]->_nUnoccupied_neighbours--;}
  }

  void Site::set_Orientation(Orientation& ort)
  { _orientation[0] = ort[0];
    _orientation[1] = ort[1];
  }

  void Site::add_neighbour(Site& n)
  { _nUnoccupied_neighbours++;
    _neighbours.push_back(&n);
  }

  int Site::num_neighbours()
  { return _neighbours.size();}

  int Site::num_unoccupied_neighbours()
  { return _nUnoccupied_neighbours;}

  Site* Site::get_neighbour(int i)
  { if(i>=0 & i<4) return _neighbours[i];}

  Site* Site::get_unoccupied_neighbour(int i)
  { int n = 0;
    for(int j=0; j < 4; j++)
    { if(_neighbours[j]->unoccupied())
      { if(n==i) return _neighbours[j];
        n++;
      }
    }
  }
      
  vector<Site*>&  Site::get_neighbours()
  { return _neighbours;}

