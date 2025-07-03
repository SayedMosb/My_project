#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <conio.h>
#define PATH "D:/codes/C++_A/Data/data-base.txt"
#define COPY "D:/codes/C++_A/Data/data-temp.txt"
using namespace std;
struct Product{
    int code;
    string name;
    float price;
    int quantity;
    string catogry;
};
vector<Product>products;
vector<Product>Cart;
string Currentrole;
string Passwordstr;

void loadProducts();
void saveProducts();
void adminMenu();
void buyerMenu();
void login();
void displayProducts();
void addProduct();
void editProduct();
void deleteProduct();
void viewSales();
void addToCart();
void viewCart();
void completePurchase();
string hashPassword(const string &password);  

void loadProducts(){
    ifstream file(PATH);
    if(file.is_open()){
        Product product;
        while (file >> product.code >> product.name >> product.price >> product.quantity >> product.catogry)
        {
            products.push_back(product);
        }
        file.close();
    }
}
void displayProducts(){
    cout << "\nAvailable Products:\n";
    for (const auto &product : products) {
        cout << "Product Name: " << product.name
            << ", Price: " << product.price
            << ", Quantity: " << product.quantity
            << ", Category: " << product.catogry <<"\n";
    }
}
void saveProducts() {
    ofstream file (PATH);
    if(file.is_open()){
        for(const auto &product:products){
            file <<product.code <<" "<<product.name <<" "<<product.price <<" "<<product.quantity <<" "<< product.catogry<<endl;
        }
    }
    file.close();
}
void addToCart() {
    string namproduct;
    int quantity1;

    cout << "Enter Name Of Product: ";
    cin >> namproduct;

    bool productFound = false;
    for (auto &product : products) {
        if (product.name == namproduct) {
            productFound = true; 
            break;
        }
    }

    if (!productFound) {
        cout << "The Product Not Found.\n";
        return;
    }

    while (true) {
        cout << "Enter Quantity Of Product: ";
        cin >> quantity1;

        if (cin.fail()) {
            cout << "Enter invalid...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break; 
    }

    for (auto &product : products) {
        if (product.name == namproduct) {
            if (product.quantity >= quantity1) {
                Product cartItem = product;
                cartItem.quantity = quantity1;
                Cart.push_back(cartItem);
                product.quantity -= quantity1;
                saveProducts();
                cout << "Product added to cart.\n";
                return;
            } else {
                cout << "Insufficient quantity available.\n";
                return;
            }
        }
    }
}

void viewCart(){
    cout << "\nShopping Cart:\n";
    float total =0.0 ;
    for (const auto &item : Cart) {
        cout << "Product Name: " << item.name
            << ", Price: " << item.price
            << ", Quantity: " << item.quantity << endl;
        total += item.price * item.quantity;
    }
    cout << "Total: " << total << endl;
}
void completePurchase(){
    viewCart();
    ofstream salesFile(COPY, ios::app);
    if (salesFile.is_open()){
        double total = 0.0;
        for (const auto &item : Cart){
            salesFile << item.name << " " << item.price << " " << item.quantity << endl;
            total += item.price * item.quantity;
        }
        salesFile << "Total: " << total << endl;
        salesFile.close();
    }
    Cart.clear();
    cout << "Purchase completed successfully!\n";
}
void buyerMenu(){
    int choice ;
    while (true)
    {
        cout << "\nBuyer Menu:\n";
        cout << "1. View Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Complete Purchase\n";
        cout << "5. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            displayProducts();
            break;
        case 2:
            addToCart();
            break;
        case 3:
            viewCart();
            break;
        
        case 4:
            completePurchase();
            break;
        
        case 5:
            cout << "Logout....\n";
            return;
        default:
            cout << "Enter The Invalid Number: ...\n";
            break;
        }
    }
}
void viewSales(){
    string line;
    double totalsales;
    ifstream file (COPY);
    if(!file.is_open()){
        cout << "Not Found File...\n";
    }
    while (getline(file,line))
    {
        cout << line << endl;
        if(line.find("Total:")!= string::npos){
            size_t pos = line.find("Total:");
            double salesamount=stod(line.substr(pos+6));
            totalsales+=salesamount;
        }
    }
    cout << "\nTotal Sales Amount: " << totalsales << endl;
    file.close();
}
void login() {
    int cho;
    cout << "Enter The Status:\n";
    cout << "1. Admin\n";
    cout << "2. Buyer\n";
    cout << "Enter Choice: ";
    cin >> cho;  
    string username, password;
    switch (cho) {
        case 1:  
            cout << "Enter username : ";
            cin >> username;
            if (username == "admin" ) {
                string adminPassword = "admin123";
                cout << "Enter password: ";
                password.clear();
                char ch;
                while (true) {
                    ch = _getch();
                    if (ch == 13) { 
                        break;
                    } else if (ch == 8) {  
                        if (password.length() > 0) {
                            password.pop_back();
                            cout << "\b \b";
                        }
                    } else {
                        password += ch;
                        cout << "*"; 
                    }
                }
                cout << endl;
                if (password == adminPassword) {
                    cout << "Admin login successful.\n";
                    Currentrole = "Admin";
                    adminMenu();   
                } else {
                    cout << "Incorrect password for Admin.\n";
                }
            } else {
                cout << "Invalid username for Admin.\n";
            }
            break;

        case 2:  
            cout << "Hello Buyer:...\n";
            buyerMenu();  
            break;

        default:
            cout << "Invalid choice, please try again.\n";
            break;
    }
}
void adminMenu() {
    string choice;
    while (true) {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Product\n";
        cout << "2. Edit Product\n";
        cout << "3. Delete Product\n";
        cout << "4. View Sales Reports\n";
        cout << "5. View Product\n";
        cout << "6. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == "1") {
            addProduct();
        } else if (choice == "2") {
            editProduct();
        } else if (choice == "3") {
            deleteProduct();
        } else if (choice == "4") {
            viewSales();
        } else if (choice == "5")
        {
            displayProducts();
        }
        else if (choice == "6") {
            cout << "Logged out from Admin Menu.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
void addProduct(){
    Product product;
    cout << "Enter product name: ";
    cin >> product.name;
    cout << "Enter price: ";
    cin >> product.price;
    cout << "Enter quantity: ";
    cin >> product.quantity;
    cout << "Enter category: ";
    cin >> product.catogry;
    products.push_back(product);
    saveProducts();
    cout << "Product added successfully!\n";
}
void editProduct() {
    string productName;
    cout << "Enter product name to edit: ";
    cin >> productName;

    bool found = false;
    for (auto &product : products) {
        if (product.name == productName) {
            found = true;
            cout << "Editing product: " << product.name << endl;
            cout << "Current price: " << product.price << ", enter new price: ";
            cin >> product.price;
            cout << "Current quantity: " << product.quantity << ", enter new quantity: ";
            cin >> product.quantity;
            saveProducts();
            cout << "Product updated successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "Product not found.\n";
    }
}
void deleteProduct(){
    string namedel;
    cout<<"Enter Name Product to delet : ";
    cin>>namedel;
    bool found =false;
    for(auto i = products.begin() ; i != products.end(); i++){
        if (i->name == namedel )
        {
            found = true;
            products.erase(i);
            saveProducts();
            cout << "Product deleted successfully!\n";
            break;
        }
        
    }
    cout << (found ? "Product found!" : "Product Not Found \n");
}

string hashPassword(const string &password){
    string hashedPassword ;
    for (auto c : password ){
        hashedPassword += to_string(int(c));
    }
    return hashedPassword;
}
int main(){
    loadProducts();
    string choice;

    while (true) {
        cout << "\nWelcome to the Online Market!\n";
        cout << "Choose an option to start:\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == "1") {
            login();
        }
        else if (choice=="2")
        {
            cout << "exit...";
            break;      
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}