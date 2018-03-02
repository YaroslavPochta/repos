#pragma once

#include <string>
#include <vector>
using namespace std;

struct Product 
{
	int ID;
	string name;
	int UPS;
	string producer;
	int price;
	int bestBefore;
	int quantity;
};

class productsList 
{
private:
	vector<Product> list;
	string outputFilename;
public:
	productsList();
	productsList(string file);
	productsList(const productsList &obj);
	void setOutputFile(string file);
	void outputList();
	void outputList(bool, bool name = false, bool ups = false, bool manufacturer = false, bool price = false, bool storage_life = false, bool number = false);
	void addProduct(Product);
	productsList namesList(string);
	void pricesByName();
	void outputNumbersOfNamesForManufacturers();
	productsList namesByLimitPriceList(string, int);
	productsList sortedByPriceAndNameList();
	productsList sortedByBestBeforeList(int);

	~productsList();
};

bool nameCompare(Product, Product);
bool producerAndNameCompare(Product, Product);
bool priceAndNameCompace(Product, Product);
bool bestBeforeCompare(Product, Product);