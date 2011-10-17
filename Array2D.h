/** Array2D.h
 *  An implementation of 2D array by Yimin Li
 */

#ifndef ARRAY2D_H
#define ARRAY2D_H

template<typename Tp>
  class Array2D
  {
  public:
    Tp *_data;
    int _dim;
    int _dim1; 
    int _dim2; 

  public:
    Array2D(){};

    Array2D(int dim1, int dim2)
    { _dim = dim1 * dim2;
      _dim1 = dim1;
      _dim2 = dim2;
      _data = new Tp[_dim];
    }

    Array2D(int dim1, int dim2, const Tp init_value)
    { _dim = dim1 * dim2;
      _dim1 = dim1;
      _dim2 = dim2;
      _data = new Tp[_dim];

      for(int i= 0; i < _dim-1; i++)
      { _data[i] = init_value;}
    }

    int dim1() const
    { return _dim1;}

    int dim2() const
    { return _dim2;}

    Tp& operator ()(const int i, const int j) const
    { return _data[i*_dim2+j];}

    Tp& operator ()(int i, int j)
    { return _data[i*_dim2+j];}
    
  };
      
#endif //ARRAY2D_H
