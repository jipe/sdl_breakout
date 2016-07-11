#ifndef BOUNDARY_H
#define BOUNDARY_H

class Boundary {
  
  public:
    virtual bool intersects(const Boundary &boundary) const = 0;
};

#endif
