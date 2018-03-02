#include "ProductsList.h"

#include <iostream>

using namespace std;

int main() 
{
	productsList products("Products.txt");

	//список товаров для заданного наименования; 
	products.setOutputFile("out1.txt");
	products.namesList("Pen").outputList();

	//средней цены каждого наименования продукта
	products.setOutputFile("out2.txt");
	products.pricesByName();

	//общего количества наименований каждого производителя
	products.setOutputFile("out3.txt");
	products.outputNumbersOfNamesForManufacturers();

	//список товаров для заданного наименования, цена которых не превосходит заданную
	products.setOutputFile("out4.txt");
	products.namesByLimitPriceList("Pen", 400).outputList();

	//общего списка товаров, состоящего из Цена Наименование ProductID UPC Производитель, упорядоченного по Цене и Наименованию.
	products.setOutputFile("out5.txt");
	products.sortedByPriceAndNameList().outputList(1, 1, 1, 1, 1, 0, 0);

	//списка продуктов, состоящего из СрокХранения Количество Наименование ProductID UPC Производитель, со сроком службы, больше заданного, упорядоченных по сроку хранения.
	products.setOutputFile("out6.txt");
	products.sortedByBestBeforeList(200).outputList(1, 1, 1, 1, 0, 1, 1);

	system("pause");
	return 0;
}