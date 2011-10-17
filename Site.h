/** site.h
 *  Site class
 */

#ifndef SITE_H
#define SITE_H

#include <vector>
using namespace std;


class Site
{
public:
  typedef int Orientation[2];


private:

  vector<Site*> _neighbours;
  Orientation _orientation;
  bool _fOccupied;

  int _nUnoccupied_neighbours;

public:

  Site(){ _fOccupied = false;}

  Site(Orientation& ort);

  Site(const int x, const int y);

  Orientation& get_Orientation();
  void set_Orientation(Orientation& ort);
  void set_Orientation(int x, int y);


  bool occupied();
  bool unoccupied();
  void set_occupied();


  void add_neighbour(Site& n);
  int num_neighbours();
  int num_unoccupied_neighbours();
  Site* get_neighbour(int i);
  Site* get_unoccupied_neighbour(int i);
  vector<Site*>&  get_neighbours();

};
#endif //SITE_H
