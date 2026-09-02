//============================================================================
// Name        : EMS.cpp
// Author      : Mansi Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;
class Product{
	int productId;
	string name;
	double price;
	int quantity;

public:
void acceptDetails(){
	cout << "enter product details: " << endl;
	cin >> productId >> name >> price >> quantity;

}
void displayDetails(bool lowStock = false )const{
	cout << left
	     << setw(8)  << productId
		 << setw(15) << name
		 << setw(12) << fixed << setprecision(2) << price
		 << setw(8)  << quantity
		 << setw(15) << totalValue();
	if (lowStock){
		cout << "<_lowStock :";
	}
	cout << endl;

}
double totalValue()const{
	return price * quantity;

}
bool isLowStock(int threshold) const{
	return quantity < threshold;
}
string getName()const{
	return name;
}
};

int main() {
	Product arr[5];
	cout << "enter product:" << endl;
	for (int i=0;i<5;i++){
		cout << " product : "<< i+1<<":";
		arr[i].acceptDetails();

	}
	int threshold;
	cout << "enter threshold: ";
	cin >> threshold ;
	cout << endl;
	cout << " =====INVENTORY REPORT=====" << endl;
	cout << left
	         << setw(8)  << "ID"
	         << setw(15) << "Name"
	         << setw(12) << "Price"
	         << setw(8)  << "Qty"
	         << setw(15) << "Total Value"
	         << endl;

	    cout << "----------------------------------------------------------"
	         << endl;

	    // Display all products
	        for (int i = 0; i < 5; i++) {}

	        // Find highest total value
	        double highestValue = arr[0].totalValue();
	        int highestIndex = 0;

	        for (int i = 1; i < 5; i++) {

	            if (arr[i].totalValue() > highestValue) {
	                highestValue = arr[i].totalValue();
	                highestIndex = i;
	            }
	        }

	        // Highest value product
	        cout << endl;
	        cout << "Highest Value Product : "
	             << arr[highestIndex].getName()
	             << " (Rs. "
	             << fixed << setprecision(2)
	             << highestValue
	             << ")" << endl;

	        // Low stock products
	        cout << "LowStock (threshold: " << threshold << ") : ";

	        bool found = false;

	        for (int i = 0; i < 5; i++) {

	            if (arr[i].isLowStock(threshold)) {

	                if (found) {
	                    cout << ", ";
	                }

	                cout << arr[i].getName();
	                found = true;
	            }
	        }
	return 0;
}
