#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "product.h"
#include "discountedProduct.h"
#include "streetMarket.h"
#include "membershipMarket.h"
#include "market.h"
#include "shoppingCart.h"


using namespace std;

int main(){

	// Variables
	string custName;
	string custAddress;
	string membershipStatus;
	bool validMembership = false;

	int storeSelection;
	bool validStore = false;
	int convertedID = 0;
	bool validID;

	bool inCheckOut = false;
	string checkoutStatus = "add";
	double finalPrice;

	string discountCode = ""; // Replace this one later
	string productId; // Replace this one later
	
	// Object variables
	product* products[5];
	shoppingCart* cart;

	// Create products
	products[0] = new product("Milk", 3.25, 6, 0);
	products[1] = new product("Bread", 5.74, 8, 1);
	products[2] = new product("Eggs", 8.99, 6, 2);
	products[3] = new product("Apples", 2.99, 6, 3);
	products[4] = new product("Oranges", 5.59, 6, 4);

	cart = new shoppingCart();
	streetMarket *streetM;
	membershipMarket *memberM;
	discountedProduct *discountProduct;

	streetM = new streetMarket("streetmarket");
	memberM = new membershipMarket("membershipmarket");
	discountProduct = new discountedProduct(1,5.74);

	// Get customer name, address and membership status
	cout << "Enter your name\n";
	cin >> custName;
	cout << endl;

	cout << "Enter your address\n";
	cin >> custAddress;
	cout << endl;

	// Validate input for membership
	while(validMembership == false){
		cout << "Do you have a membership? (Y/N) \n";
		cin >> membershipStatus;

		if (membershipStatus == "Y" || membershipStatus == "n" || membershipStatus == "N" || membershipStatus == "y"){
			// Add to customer class
			validMembership = true;
		} else {
			cout << "Invalid input, please enter Y or N \n" << endl;
			validMembership = false;
		}
	}
	cout << endl;
	cout << "Welcome " << custName << "\n";

	// Validate Store details
	while(validStore == false){
		cout << "Please select a market: Street Market (1) or Membership Market (2) \n" << endl;
		cin >> storeSelection;

		if (storeSelection == 1 || storeSelection == 2){
			validStore = true;
			if (storeSelection == 2){
				if (membershipStatus == "n" || membershipStatus == "N"){
					validStore = false;
					cout << "You do not have a membership to shop in this market \n" << endl;	
				}
			}
		} else {
			validStore = false;
			cout << "Invalid input. Please enter 1 or 2 <\n" << endl;
		}	
	}

	if (storeSelection == 1){
		discountCode = streetM->getDiscountedCode();
		cout << endl;
	} else if (storeSelection == 2){
		discountCode = memberM->getDiscountedCode();
		cout << endl;
	}
	
	cout << "Here is a discount code to apply at checkout: " << discountCode << endl << "\n";
	// Display Products here
	while(inCheckOut == false){
		if (checkoutStatus == "add"){
			// Do not add if cart is already full (5 items max)
			cout << endl;
			cout << "Choose from the below products: \n";
			for (int i = 0; i < 5; i++){
				cout << products[i]->name << " " << products[i]->price << " " << products[i]->id << "\n";
			}
			// telling the user which product is on discount
			cout << "Today's special product that is on discount is Bread !" << endl; 
			cout << endl;

			// adding items
			cin >> productId;
			cout << endl;

			if (productId !="0" && productId !="1" && productId !="2" && productId !="3" && productId !="4"){
				cout << "please enter the correct product ID" << endl;
			} else {
				stringstream convert(productId);
				
				convert >> convertedID;

				if (discountProduct->getId() == convertedID){
					cart->setTotalPrice(cart->getTotalPrice() + discountProduct->price);
				} else {
					cart->setTotalPrice(cart->getTotalPrice() + products[convertedID]->price);
				}

				validID = cart->addItem(convertedID);


				if (validID == false){
					cout << "your shopping cart is full !" << endl;
				} 
			}

			// Before adding to class variable check its not a letter
			// Add item to shopping cart here
			// Update shopping cart total
				
			checkoutStatus = "next";
		} else if(checkoutStatus == "remove"){
			cout << "Which item would you like to remove? " << endl;

			// removing items
			// Maybe print out all the IDs of the items from the cart?
			cin >> productId;

			if (productId !="1" && productId !="2" && productId !="3" && productId !="4" && productId !="5"){
				cout << "please enter the correct product ID" << endl;
			} else {
				stringstream convert(productId);
				convert >> convertedID;
				cart->setTotalPrice(cart->getTotalPrice() - products[convertedID]->price);
				cart->removeItem(convertedID);
			}
			// Remove item from shopping cart here
			// Update shopping cart totals
				
			
			checkoutStatus = "next";
		} else if(checkoutStatus == "checkout"){
			// Display totals
			inCheckOut = true;
		} else {
			cout << "Invalid Entry, enter add, remove or checkout";
			checkoutStatus = "next";
		}
		if (checkoutStatus == "next"){
			cout << "What would you like to do next?\n";
			cout << "Add more products to cart(add) \n";
			cout << "Remove a product from your cart (remove) \n";
			cout << "Checkout (checkout) \n";
			cin >> checkoutStatus;
		}
	}

	// Shopping Cart
	cout << endl;

	// Displaying Total Items
	cout << "The total amount of items are: " << cart->getTotalItems() << endl;

	// Displaying total price
	cout << "The total price is: " << cart->getTotalPrice()<< "\n";

	// Ask for discount code
	cout << "Please enter your discount code: " << endl;
	cin >> discountCode;
	cout << endl;

	// Displaying Total Price after discount 
		if (discountCode == memberM->getDiscountedCode() || discountCode == streetM->getDiscountedCode()){
			finalPrice = cart->getTotalPrice();
			
			finalPrice = finalPrice * 0.8;
			cout << "Your total price after discount is: " << finalPrice << endl;
		} else {
			cout << "Your discount code is invalid " << endl;
			cout << endl;
			cout << "Your total price is still : " << cart->getTotalPrice() << endl;
		}
	

	return 0;
}