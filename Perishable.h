// Workshop <Milestone 5>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <Perishable.h>

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H

namespace ama{

  class Perishable : public Product{

    Date expiry_date;

  public:

    Perishable() ; 
    std::ostream& write(std::ostream& out, int writeMode) const;
    std::istream& read(std::istream& in, bool interractive);


  }
}

#endif
