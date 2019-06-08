// Workshop <Milestone 3>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <Product.h>

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H

#include <iostream>
#include <string>
#include "ErrorState.h"
#include "iProduct.h"

namespace ama{


	class Product : public iProduct{

		char mSku[max_length_sku + 1];
		char mUnit[max_length_unit + 1];
		char* mName;
		int mQuantityOnHand;
		int mQuantityNeeded;
		double mPrice;
		bool mTaxable;
		char mType[8];
		ErrorState mErrState;

		void copy(const char* sku, const char* name, const char* unit,
			double price, int qNeeded, int qHand, bool taxable);
		void getDottedName(char* temp, const char* name) const;

		void putName(const char* name);
		void readString(std::istream& in, char* out);
		double readDouble(std::istream& in);
		bool readBool(std::istream& in);
		int readInt(std::istream& in);

		void inputString(std::istream& in, char* out);
		bool inputDouble(std::istream& in, double& value);
		int inputBool(std::istream& in);
		bool inputInt(std::istream& in, int& value);
		bool isNumber(const std::string& str);

	public:
		Product();
		Product(char t);
		Product(
			const char* sku, const char* name, const char* unit,
			double price = 0.0, int qNeeded = 0, int qHand = 0, bool taxable = true
			);
		Product(const Product& prod);
		~Product();

		void message(const char* pText);
		bool isClear() const;

		void operator=(const Product& prod);
		int operator+=(int cnt);
		bool operator==(const char* sku)const;
		bool operator>(const char* sku);
		bool operator>(const iProduct& other) const;

		int qtyAvailable() const;
		int qtyNeeded() const;
		const char* name() const;
		double total_cost() const;
		bool isEmpty() const;

		std::istream& read(std::istream& in, bool interractive);
		std::ostream& write(std::ostream& out, int writeMode) const;

	};
}

#endif
