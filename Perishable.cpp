// Workshop <Milestone 5>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <Perishable.h>

#include <iostream>
#include "Perishable.h"

using namespace std;

namespace ama{

  Perishable() : Product('P'){


  }

  std::ostream& Perishable::write(std::ostream& out, int writeMode) const{

    Product::write(out, writeMode);

    if (!isClear()){

			out << mErrState;
			return out;
		}

		if (isEmpty())
			return out;

    else if(writeMode == write_human){

      out << "Expiry Date: ";
      expiry_date.write(out);
    }else if(writeMode == write_table){

      out << " ";
      expiry_date.write(out);
      out << " |";


    }else if(writeMode == write_condensed){

      out << ".";
      expiry_date.write(out);

    }

    return out;

  }

  std::istream& Perishable::read(std::istream& in, bool interractive){

    Product::read(in, interractive);

    if(interractive == true){

      std::cout << "Expiry date (YYYY/MM/DD): ";
      expiry_date.read(in);

    }

  }




}
