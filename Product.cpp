// Workshop <Milestone 3>
// Name: <Yuan-Hsi Lee>
// Student #: <106936180>
// Course: OOP244 Winter 2019
// File: <Product.cpp>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "Product.h"

using namespace std;

namespace ama
{
	Product::Product()
	{
		strcpy(mSku, "");
		mName = nullptr;
		strcpy(mUnit, "");
		mPrice = 0.0;
		mQuantityOnHand = 0;
		mQuantityNeeded = 0;
		mTaxable = true;
		strcpy(mType, "N");
	}


	Product::Product(char t)
	{
		strcpy(mSku, "");
		mName = nullptr;
		strcpy(mUnit, "");
		mPrice = 0.0;
		mQuantityOnHand = 0;
		mQuantityNeeded = 0;
		mTaxable = true;
		mType[0] = t; mType[1] = 0;
	}


	Product::Product(
		const char* sku, const char* name, const char* unit,
		double price, int qNeeded, int qHand, bool taxable
	)
	{
		copy(sku, name, unit, price, qNeeded, qHand, taxable);
		strcpy(mType, "N");
	}


	Product::Product(const Product& prod)
	{
		*this = prod;
	}


	Product::~Product()
	{
		if (mName != nullptr)
		{
			delete[] mName;
			mName = nullptr;
		}
	}


	void Product::operator=(const Product& prod)
	{
		copy(prod.mSku, prod.mName, prod.mUnit, prod.mPrice, prod.mQuantityNeeded, prod.mQuantityOnHand, prod.mTaxable);
	}


	void Product::message(const char* pText)
	{
		mErrState.message(pText);
	}


	bool Product::isClear() const
	{
		return !mErrState;
	}


	int Product::operator+=(int cnt)
	{
		if (cnt > 0)
			mQuantityOnHand += cnt;

		return mQuantityOnHand;
	}


	bool Product::operator==(const char* sku)const{

		if (mSku == nullptr || sku == nullptr)
			return false;

		return (strcmp(mSku, sku) == 0) ? true : false;
	}


	bool Product::operator>(const char* sku)
	{
		if (mSku == nullptr || sku == nullptr)
			return false;

		return (strcmp(mSku, sku) > 0) ? true : false;
	}


	bool Product::operator>(const iProduct& other) const
	{
		if (mName == nullptr || other.name() == nullptr)

			return false;

		return (strcmp(mName, other.name()) > 0) ? true : false;
	}


	int Product::qtyAvailable() const
	{
		return mQuantityOnHand;
	}


	int Product::qtyNeeded() const
	{
		return mQuantityNeeded;
	}

	const char* Product::name() const{

		if(mName != nullptr){

			return mName;
		}else{
			return nullptr;
		}
	}


	double Product::total_cost() const
	{
		return qtyAvailable() * mPrice * (mTaxable ? (1.0 + tax_rate) : 1.0);
	}


	bool Product::isEmpty() const
	{
		return (mName == nullptr) ? true : false;
	}


	std::istream& Product::read(std::istream& in, bool interractive)
	{
		char sku[max_length_sku];
		char name[128];
		char unit[max_length_unit];
		bool taxable = false;
		double price = -100.0;
		int quantityOnHand = -1;
		int quantityNeeded = -1;

		if (interractive == false)
		{
			readString(in, sku);
			readString(in, name);
			readString(in, unit);
			price = readDouble(in);
			taxable = readBool(in);
			quantityOnHand = readInt(in);
			quantityNeeded = readInt(in);

			// Save the inputs
			copy(sku, name, unit, price, quantityNeeded, quantityOnHand, taxable);
		}
		else
		{
			cout.setf(ios::right);

			cout << setw(max_length_label) << "Sku: ";
			in >> sku;

			cout << setw(max_length_label) << "Name (no spaces): ";
			in >> name;

			cout << setw(max_length_label) << "Unit: ";
			in >> unit;

			cout << setw(max_length_label) << "Taxed? (y/n): ";
			char cTaxable[32];
			in >> cTaxable;
			if (strcmp(cTaxable, "Y") == 0 || strcmp(cTaxable, "y") == 0 ||
				strcmp(cTaxable, "N") == 0 || strcmp(cTaxable, "n") == 0)
			{
				if (strcmp(cTaxable, "Y") == 0 || strcmp(cTaxable, "y") == 0)
					taxable = true;
				else
					taxable = false;
			}
			else
			{
				in.setstate(ios::failbit);
				mErrState.message("Only (Y)es or (N)o are acceptable!");
				cout.unsetf(ios::right);
				return in;
			}

			cout << setw(max_length_label) << "Price: ";
			in >> price;
			if(price == 0)
			{
				in.setstate(ios::failbit);
				mErrState.message("Invalid Price Entry!");
				cout.unsetf(ios::right);
				return in;
			}

			cout << setw(max_length_label) << "Quantity on hand: ";
			in >> quantityOnHand;
			if(quantityOnHand == 0)
			{
				in.setstate(ios::failbit);
				mErrState.message("Invalid Quantity Available Entry!");
				cout.unsetf(ios::right);
				return in;
			}

			cout << setw(max_length_label) << "Quantity needed: ";
			in >> quantityNeeded;
			if(quantityNeeded == 0)
			{
				in.setstate(ios::failbit);
				mErrState.message("Invalid Quantity Needed Entry!");
				cout.unsetf(ios::right);
				return in;
			}

			cout.unsetf(ios::right);

			// Save the inputs
			copy(sku, name, unit, price, quantityNeeded, quantityOnHand, taxable);
		}

		return in;
	}


	std::ostream& Product::write(std::ostream& out, int writeMode) const{

		if (isClear() == false){

			out << mErrState;
			return out;
		}

		if (isEmpty() == true)
			return out;

		if (writeMode == write_condensed){

			out << mType << "," << mSku << "," << mName << "," << mUnit << "," << mPrice << "," << mTaxable << "," << mQuantityOnHand << "," << mQuantityNeeded;
		}
		else if (writeMode == write_table){
			
			char tempName[17];
			getDottedName(tempName, mName);

			out << " "; out.setf(ios::right); out << setw(max_length_sku) << mSku << " | "; out.unsetf(ios::right);
			out.setf(ios::left); out << setw(max_length_sku) << tempName << " | ";
			out.setf(ios::left); out << setw(10) << mUnit << " | ";
			out.setf(ios::right); out << setw(7) << fixed << setprecision(2) << mPrice << " | ";
			out.setf(ios::right); out << setw(3) << (mTaxable ? "yes" : "no") << " | ";
			out.setf(ios::right); out << setw(6) << mQuantityOnHand << " | ";
			out.setf(ios::right); out << setw(6) << mQuantityNeeded << " |";

			out.unsetf(ios::right);
		}
		else if (writeMode == write_human)
		{
			out.setf(ios::right);

			out << setw(max_length_label) << "Sku: " << mSku << endl;
			out << setw(max_length_label) << "Name: " << mName << endl;
			out << setw(max_length_label) << "Price: " << fixed << setprecision(2) << mPrice << endl;
			out << setw(max_length_label) << "Price after Tax: " << fixed << setprecision(2) << (mTaxable ? mPrice * (1.0 + tax_rate) : mPrice) << endl;
			out << setw(max_length_label) << "Quantity Available: " << mQuantityOnHand << " " << mUnit << endl;
			out << setw(max_length_label) << "Quantity Needed: " << mQuantityNeeded << " " << mUnit << endl;

			out.unsetf(ios::right);
		}

		return out;
	}


	void Product::copy(const char* sku, const char* name, const char* unit,
		double price, int qNeeded, int qHand, bool taxable)
	{
		if (name == nullptr)
		{
			strcpy(mSku, "");
			mName = nullptr;
			strcpy(mUnit, "N");
			mPrice = 0.0;
			mQuantityOnHand = 0;
			mQuantityNeeded = 0;
			mTaxable = true;
		}
		else
		{
			// sku
			if (sku != nullptr)
				strcpy(mSku, sku);
			else
				strcpy(mSku, "");

			// name
			if (name != nullptr && strlen(name) > 0)
			{
				mName = new char[strlen(name) + 1];
				strcpy(mName, name);
			}
			else
				mName = nullptr;

			// unit
			if (unit != nullptr)
				strcpy(mUnit, unit);
			else
				strcpy(mUnit, "");

			mPrice = price;
			mQuantityOnHand = qHand;
			mQuantityNeeded = qNeeded;
			mTaxable = taxable;
		}
	}


	void Product::getDottedName(char* temp, const char* name) const
	{
		if (temp == nullptr || name == nullptr || strlen(name) == 0)
			return;

		if (strlen(name) >= 16)
		{
			strncpy(temp, name, 13);
			temp[13] = '\0';
			strcat(temp, "...");
		}
		else
		{
			strcpy(temp, name);
		}
	}


	void Product::readString(std::istream& in, char* out)
	{
		if (out == nullptr)
			return;

		string str;
		std::getline(in, str, ',');
		strcpy(out, str.c_str());
	}


	double Product::readDouble(std::istream& in)
	{
		string str;
		std::getline(in, str, ',');
		return std::stod(str);
	}


	bool Product::readBool(std::istream& in)
	{
		string str;
		std::getline(in, str, ',');
		return (str == "1" ? true : false);
	}


	int Product::readInt(std::istream& in)
	{
		string str;
		std::getline(in, str, ',');
		return std::stoi(str);
	}
}
