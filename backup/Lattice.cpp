#include "Lattice.h"

#include <iostream>
inline Lattice::Lattice(){}

inline Lattice::Lattice(int N1, int N2) : Array2D<Site*>(N1,N2)
{ create_sites(N1, N2);
  Site* sp =  (*this)(2,2);
  
  for(int i=1; i < N1; i++)
  { for(int j=1; j < N2; j++)
    {create_neighbours(i,j);
     cout << sp->num_neighbours()<< "++++"<<endl;
     cout << "*" << i << " "<<j <<endl;
     cout << "**" <<endl;
    }
  }
//  create_neighbour_lists(N1, N2);
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

  cout << s.num_neighbours() <<endl;
  int x1 = x+1;
  int y1 = y;
  check_boundary(x1,y1);
  Site& nb = get_site(x1, y1);
  s.add_neighbour(nb);

  cout<< x1 << " " << y1 << endl;
  x1 = x;
  y1 = y+1;
  check_boundary(x1,y1);
  nb = get_site(x1, y1);
  s.add_neighbour(nb);

  cout<< x1 << " " << y1 << endl;
  x1 = x-1;
  y1 = y;
  check_boundary(x1,y1);
  nb = get_site(x1, y1);
  s.add_neighbour(nb);

  cout<< x1 << " " << y1 << endl;
  x1 = x;
  y1 = y-1;
  check_boundary(x1,y1);
  nb = get_site(x1, y1);
  s.add_neighbour(nb);
  cout<< x1 << " " << y1 << endl;
  cout << s.num_neighbours() <<endl;
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
  Site::Orientation ort;
  ort[0]= x;
  ort[1]= y;
  (*this)(ort[0],ort[1]) = sp;
}

inline Site* Lattice::get_site_pointer(int x, int y)
{ 
  Site::Orientation ort;
  ort[0]= x;
  ort[1]= y;
  return (*this)(ort[0],ort[1]);
}

inline Site& Lattice::get_site(const int x, const int y)
{ Site* sp = get_site_pointer(x,y);
  return *sp;
}



