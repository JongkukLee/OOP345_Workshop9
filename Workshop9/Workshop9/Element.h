// OOP345 Workshop 9: Smart Pointers
// File Description.cpp
// Version 1.0
// Date 2017-07-28
// Author Jongkuk Lee ( jlee465@myseneca.ca, 127730158 )
// Description
//  The Description class holds a product code and a user - friendly description.
//  The Price class holds a product code and the current price.
//  The Product class holds a user - friendly description and the current price of a product.
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
// Workshop 9 - Smart Pointers
// Element.h

#ifndef W9_DESCRIPTION_H
#define W9_DESCRIPTION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;

namespace w9 {

	struct Description {
		unsigned code;
		std::string desc;
		bool load(std::ifstream& f) {
			f >> code >> desc;
			return f.good();
		}
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWD)
				<< desc << std::endl;
		}
	};

	struct Price {
		unsigned code;
		double price;
		bool load(std::ifstream& f) {
			f >> code >> price;
			return f.good();
		}
		void display(std::ostream& os) const {
			os << std::setw(FWC) << code << std::setw(FWP)
				<< price << std::endl;
		}
	};

	struct Product {
		std::string desc;
		double price;
		Product() {}
		Product(const std::string& str, double p) : desc(str), price(p) {
      if (price < 0) throw std::string("\n*** Negative prices are invalid ***");
    }
		void display(std::ostream& os) const {
			os << std::setw(FWD) << desc << std::setw(FWP)
				<< price << std::endl;
		}
	};
}
#endif
