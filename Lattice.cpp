#include "Lattice.h"

inline Lattice::Lattice(){}

inline Lattice::Lattice(int N1, int N2) : Array2D<Site*>(N1,N2)
{ create_sites(N1, N2);
  
  create_neighbour_lists(N1, N2);
}

inline void  Lattice::create_sites(int N1, int N2)
{ Site* sp;
  for(int i=0; i < N1; i++)
  { for(int j=0; j < N2; j++)
    { sp = new Site(i,j);
      set_site_pointer(i,j,sp);
    }
  }
}

inline void Lattice::create_neighbour_lists(int N1, int N2)
{ for(int i=0; i < N1; i++)
  { for(int j=0; j < N2; j++)
    {create_neighbours(i,j);}
  }
} 

inline void Lattice::create_neighbours(int x, int y)
{ check_boundary(x,y);
  Site& s = get_site(x,y);

  int x1 = x+1;
  int y1 = y;
  check_boundary(x1,y1);
  Site& nb1 = get_site(x1, y1);
  s.add_neighbour(nb1);

  x1 = x;
  y1 = y+1;
  check_boundary(x1,y1);
  Site& nb2 = get_site(x1, y1);
  s.add_neighbour(nb2);

  x1 = x-1;
  y1 = y;
  check_boundary(x1,y1);
  Site& nb3 = get_site(x1, y1);
  s.add_neighbour(nb3);

  x1 = x;
  y1 = y-1;
  check_boundary(x1,y1);
  Site& nb4 = get_site(x1, y1);
  s.add_neighbour(nb4);

}

inline void Lattice::check_boundary(int& x, int& y)
{ 
  x = x % this->dim1();
  if(x < 0) x = x + this->dim1();

  y = y % this->dim2();
  if(y < 0) y = y + this->dim2();
} 

inline void Lattice::check_boundary(Site::Orientation& ort)
{ check_boundary(ort[0],ort[1]);}

inline void Lattice::set_site_pointer(int x, int y, Site* sp)
{ check_boundary(x,y);
  (*this)(x,y) = sp;
}

inline Site* Lattice::get_site_pointer(int x, int y)
{ Array2D<Site*>& as =  *this;
  check_boundary(x,y);
  return as(x,y);
}

inline Site& Lattice::get_site(int x, int y)
{ Site* sp = (Site*) get_site_pointer(x,y);
  return *sp;
}

