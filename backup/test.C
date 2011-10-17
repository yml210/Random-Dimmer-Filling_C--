#include "test.h"

inline Lattice::Lattice(int N1, int N2) : Array2D<Site*>(N1,N2)
{ create_sites(N1, N2);
  create_neighbour_lists(N1, N2); 
}

inline void  Lattice::create_sites(int N1, int N2)
{ Site* sp;
  Site::set_boundary(N1, N2);
  for(int i=0; i < N1; i++)
  { for(int j=0; j < N2; j++)
    { sp = new Site(i,j);
      set_site_pointer(i,j,sp);
    }
  }
}

inline void Lattice::create_neighbours(int x, int y)
{ Site& s = get_site(x,y);
  Site& nb = get_site(x+1, y);
  s.add_neighbour(nb);

  nb = get_site(x, y+1);
  s.add_neighbour(nb);
  nb = get_site(x-1, y);
  s.add_neighbour(nb);

  nb = get_site(x, y-1);
  s.add_neighbour(nb);
}

inline void Lattice::create_neighbour_lists(int N1, int N2)
{ for(int i=0; i < N1; i++)
  { for(int j=0; j < N2; j++)
    {create_neighbours(i,j);}
  }
} 


inline void Lattice::set_site_pointer(const int x, const int y, Site* sp)
{ Site::Orientation ort;
  ort[0]= x;
  ort[1]= y;
  Site::check_boundary(ort);
  (*this)(ort[0],ort[1]) = sp;
}

inline Site* Lattice::get_site_pointer(int x, int y)
{ Site::Orientation ort;
  ort[0]= x;
  ort[1]= y;
  Site::check_boundary(ort);
  return (*this)(ort[0],ort[1]);
}

inline Site& Lattice::get_site(const int x, const int y)
{ Site* sp = get_site_pointer(x,y);
  return *sp;
}



