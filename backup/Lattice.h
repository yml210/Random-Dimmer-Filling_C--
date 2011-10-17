/** lattice.h
 *  Lattice class
 */

#ifndef LATTICE_H
#define LATTICE_H

#include "Array2D.h"
#include "Site.h"

class Lattice : public Array2D<Site*>
{

public:
  Lattice(); 

  Lattice(int N1, int N2);
   
  void create_neighbours(int x, int y);

  void create_sites(int N1, int N2);

  void create_neighbour_lists(int N1, int N2);

      
  void set_site_pointer(const int x, const int y, Site* sp);

  Site* get_site_pointer(int x, int y);

  Site& get_site(const int x, const int y);

  void check_boundary(int& x, int& y);
  void check_boundary(Site::Orientation& ort);
   
};

#endif //LATTICE_H
