#include "ProductsList.h"

#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

productsList::productsList() {}
productsList::productsList(string file) 
{
	ifstream in(file);

	Product curProduct;

	int n;
	in >> n;

	for (int i = 0; i < n; ++i) 
	{
		in >> curProduct.ID;
		in >> curProduct.name;
		in >> curProduct.UPS;
		in >> curProduct.producer;
		in >> curProduct.price;
		in >> curProduct.bestBefore;
		in >> curProduct.quantity;

		list.push_back(curProduct);
	}
	in.close();
}
productsList::productsList(const productsList &obj)
{
	this->list = obj.list;
	this->outputFilename = obj.outputFilename;
}
void productsList::setOutputFile(string file) 
{
	this->outputFilename = file;
}
void productsList::outputList() {
	ofstream out(outputFilename);

	for (int i = 0; i < list.size(); ++i) {
		out << setw(7) << list[i].ID << "  ";
		out << setw(10) << list[i].name << "  ";
		out << setw(10) << list[i].UPS << "  ";
		out << setw(5) << list[i].producer << "  ";
		out << setw(6) << list[i].price << "  ";
		out << setw(6) << list[i].bestBefore << "  ";
		out << setw(6) << list[i].quantity << endl;
	}
	out.close();
}
void productsList::outputList(bool ID, bool name, bool UPS, bool producer, bool price, bool bestBefore, bool quantity) 
{
	ofstream fout(outputFilename);

	for (int i = 0; i < list.size(); ++i) 
	{
		if (ID == true) fout << setw(10) << list[i].ID << " ";
		if (name == true) fout << setw(10) << list[i].name << " ";
		if (UPS == true) fout << setw(10) << list[i].UPS << " ";
		if (producer == true) fout << setw(10) << list[i].producer << " ";
		if (price == true) fout << setw(10) << list[i].price << " ";
		if (bestBefore == true) fout << setw(10) << list[i].bestBefore << " ";
		if (quantity == true) fout << setw(10) << list[i].quantity << " ";
		fout << "\n";
	}
	fout.close();
}
void productsList::addProduct(Product product)
{
	this->list.push_back(product);
}
bool nameCompare(Product product1, Product product2)
{
	return (product1.name < product2.name);
}
bool producerAndNameCompare(Product product1, Product product2)
{
	if (product1.producer < product2.producer) return true;
	else if (product1.producer > product2.producer) return false;
	else if (product1.producer == product2.producer) return (product1.name < product2.name);
}
bool priceAndNameCompace(Product product1, Product product2)
{
	if (product1.price < product2.price) return true;
	else if (product1.price > product2.price) return false;
	else if (product1.price == product2.price) return (product1.name < product2.name);
}
bool bestBeforeCompare(Product product1, Product product2)
{
	return (product1.bestBefore < product2.bestBefore);
}
productsList productsList::namesList(string name) 
{
	productsList newProductsList;
	newProductsList.setOutputFile(outputFilename);

	for (int i = 0; i < list.size(); ++i) 
		if (list[i].name == name) 
			newProductsList.addProduct(list[i]);

	return newProductsList;
}
void productsList::pricesByName() 
{
	ofstream fout(outputFilename);

	productsList products(*this);
	sort(products.list.begin(), products.list.end(), nameCompare);

	string curPrice;
	int counter = 0;
	int total = 0;

	if (products.list.size() != 0) {
		curPrice = products.list[0].name;
		fout << setw(10) << "Name" << setw(20 + 2) << "Average_price\n\n";
	}

	for (int i = 0; i < products.list.size(); ++i) 
	{
		if (products.list[i].name == curPrice) 
		{
			++counter;
			total += products.list[i].price;
		}
		else 
		{
			fout << setw(10) << curPrice << setw(20) << total / counter << "\n";
			counter = 0;
			total = 0;
			curPrice = products.list[i].name;
			--i;
		}
		if (i == products.list.size() - 1)
			fout << setw(10) << curPrice << setw(20) << total / counter << "\n";
	}
	fout.close();
}
void productsList::outputNumbersOfNamesForManufacturers() 
{
	ofstream fout(outputFilename);

	productsList products(*this);
	sort(products.list.begin(), products.list.end(), producerAndNameCompare);

	string curProducer;
	string curName;
	int counter = 0;

	if (products.list.size() != 0) 
	{
		curProducer = products.list[0].producer;
		curName = products.list[0].name;
		counter = 1;
		fout << setw(20) << "Producer " << setw(20) << "Number of names:\n\n";
	}

	for (int i = 0; i < products.list.size(); ++i) 
	{
		if (products.list[i].producer == curProducer) 
		{
			if (products.list[i].name != curName) 
			{
				counter++;
				curName = products.list[i].name;
			}
		}
		else 
		{
			fout << setw(20) << curProducer << setw(20) << counter << "\n";
			counter = 1;
			curProducer = products.list[i].producer;
			curName = products.list[i].name;
			i--;
		}
		if (i == products.list.size() - 1) 
			fout << setw(20) << curProducer << setw(20) << counter << "\n";
	}
	fout.close();
}
productsList productsList:: namesByLimitPriceList(string name, int priceLimit) 
{
	productsList newProductsList;
	newProductsList.setOutputFile(outputFilename);

	for (int i = 0; i < list.size(); ++i) 
		if (list[i].name == name && list[i].price <= priceLimit)
			newProductsList.addProduct(list[i]);
		
	return newProductsList;
}
productsList productsList::sortedByPriceAndNameList() 
{
	productsList newProductsList(*this);

	sort(newProductsList.list.begin(), newProductsList.list.end(), priceAndNameCompace);

	return newProductsList;
}
productsList productsList::sortedByBestBeforeList(int bestBefore) 
{
	productsList newProductsList;
	newProductsList.setOutputFile(outputFilename);

	for (int i = 0; i < list.size(); ++i)
		if (list[i].bestBefore <= bestBefore)
			newProductsList.addProduct(list[i]);

	sort(newProductsList.list.begin(), newProductsList.list.end(), bestBeforeCompare);

	return newProductsList;
}
productsList::~productsList() {}