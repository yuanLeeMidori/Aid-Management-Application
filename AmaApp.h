// Workshop <Milestone 5>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <AmaApp.h>


#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H

namespace ama{

  class AmaApp{

    char m_filename[256];
    iProduct* m_products[100];
    int m_noOfProducts;

 
    void pause() const;
    int menu() const; 
    void loadProductRecords();
    void saveProductRecords() const;
    void listProducts() const;
    void deleteProductRecord(iProduct* product);
    void sort();
    iProduct* find(const char* sku) const;//
    void addQty(iProduct* product);
    void addProduct(char tag);


  public:

    AmaApp(const char* filename, iProduct* product, int numberOfProduct);
    ~AmaApp();
    int run();


  }


}
