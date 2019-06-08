// Workshop <Milestone 5>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <AmaApp.cpp>


#include <iostream>
#include "AmaApp.h"

using namespace std;

namespace ama{

  void AmaApp::pause() const{

    char press;
    cout << "Press Enter to continue..." << endl;
    cin.ignore(2000, '\n');
    cin >> press;


  }

  int AmaApp::menu() const{


    int selection;

    cout << "Disaster Aid Supply Management Program" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1- List products" << endl;
    cout << "2- Search product" << endl;
    cout << "3- Add non-perishable product" << endl;
    cout << "4- Add perishable product" << endl;
    cout << "5- Add to product quantity" << endl;
    cout << "6- Delete product" << endl;
    cout << "7- Sort products" << endl;
    cout << "0- Exit program" << endl;
    cout << "> ";
    cin.ignore(2000, '\n');
    cin >> selection;

    if(selection >= 0 && selection <= 7){

      return selection;

    }else{

      return -1;
    }

  }

  void AmaApp::loadProductRecords(){



  }

  void AmaApp::saveProductRecords() const{

    for(int i = 0 ; i <= m_noOfProducts; i++){


    }

  }

  void AmaApp::listProducts() const{

    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "| Row |     SKU | Product Name     | Unit       |   Price | Tax |   QtyA |   QtyN | Expiry     |" << endl;
    cout << "|-----|---------|------------------|------------|---------|-----|--------|--------|------------|" << endl;

    for(int i = 0; i <= m_noOfProducts; i++){

      cout << "|";
      cout.setf


    }

  }



  int run(){

    int sku;
    if(menu() == 1){

      AmaApp::listProducts();

    }else if(menu() == 2){

      cout << "Please enter the product SKU: ";
      cin >> sku;

      if(find(sku) != nullptr){

        iProduct* ptr = find(sku);
        ptr.write(out, write_human);

      }else{

        cout << "No such product!" << endl;

      }

    }else if(menu() == 3){


    }




  }


}
