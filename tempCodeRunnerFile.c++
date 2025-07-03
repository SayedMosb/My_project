#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;

// تعريف مسارات الملفات
#define DATABASE_FILE "database.txt"
#define TEMP_FILE "temp.txt"

class Shopping {
private:
    int p_code;
    float price;
    float discount;
    string p_name;
    int quantity;
    string category;  // قسم المنتج

public:
    Shopping() : p_code(0), price(0.0f), discount(0.0f), quantity(0), category("") {}  // Constructor initialization

    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remove_1();
    void list();
    void listByCategory(const string &category);
    void receipt();
};

// القائمة الرئيسية
void Shopping::menu() {
    int choice;
    string email, password;

    while (true) {
        cout << "\nSupermarket Main Menu";
        cout << "\n1. Administrator";
        cout << "\n2. Buyer";
        cout << "\n3. Exit";
        cout << "\nPlease select: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Please login\n";
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter password: ";
                cin >> password;

                if (email == "admin@email.com" && password == "admin123") {
                    administrator();
                } else {
                    cout << "Invalid username/password\n";
                }
                break;
            case 2:
                buyer();
                break;
            case 3:
                exit(0);
            default:
                cout << "Please select from the given options\n";
        }
    }
}

// القائمة الخاصة بالمدير
void Shopping::administrator() {
    int choice;
    while (true) {
        cout << "\nAdministrator Menu";
        cout << "\n1. Add Product";
        cout << "\n2. Modify Product";
        cout << "\n3. Delete Product";
        cout << "\n4. List Products";
        cout << "\n5. Back to Main Menu";
        cout << "\nPlease enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                remove_1();
                break;
            case 4:
                list();
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice\n";
        }
    }
}

// إضافة منتج
void Shopping::add() {
    fstream data;
    data.open(DATABASE_FILE, ios::app | ios::out);
    if (!data) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }

    cout << "Add New Product\n";

    while (true) {
        cout << "Product Code (numeric): ";
        if (!(cin >> p_code)) {
            cout << "Invalid input! Please enter a valid numeric product code.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        bool exists = false;
        fstream checkFile(DATABASE_FILE, ios::in);
        int existingCode;
        string existingName, existingCategory;
        float existingPrice, existingDiscount;
        int existingQuantity;

        while (checkFile >> existingCode >> existingName >> existingPrice >> existingDiscount >> existingQuantity >> existingCategory) {
            if (existingCode == p_code) {
                exists = true;
                break;
            }
        }
        checkFile.close();

        if (exists) {
            cout << "This product code already exists. Please enter a unique code.\n";
        } else {
            break;
        }
    }

    cout << "Product Name: ";
    cin.ignore();
    getline(cin, p_name);

    cout << "Product Category (e.g., Fruits, Vegetables, Detergents): ";
    getline(cin, category);

    while (true) {
        cout << "Price: ";
        if (cin >> price) break;
        cout << "Invalid input! Please enter a valid numeric price.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Discount: ";
        if (cin >> discount) break;
        cout << "Invalid input! Please enter a valid numeric discount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Quantity: ";
        if (cin >> quantity && quantity >= 0) break;
        cout << "Invalid input! Quantity must be a non-negative number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    data << p_code << " " << p_name << " " << price << " " << discount << " " << quantity << " " << category << endl;
    data.close();

    cout << "Record inserted successfully.\n";
}

// تعديل منتج
void Shopping::edit() {
    cout << "Edit functionality is not implemented yet.\n";
}

// حذف منتج
void Shopping::remove_1() {
    fstream data, temp;
    int p_code_to_remove;

    cout << "Enter the Product Code to Remove: ";
    cin >> p_code_to_remove;

    data.open(DATABASE_FILE, ios::in);
    temp.open(TEMP_FILE, ios::out);

    if (!data || !temp) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    bool found = false;
    while (data >> p_code >> p_name >> price >> discount >> quantity >> category) {
        if (p_code == p_code_to_remove) {
            found = true;
            continue;
        }
        temp << p_code << " " << p_name << " " << price << " " << discount << " " << quantity << " " << category << endl;
    }
    data.close();
    temp.close();

    if (!found) {
        cout << "Product Not Found\n";
        std::remove(TEMP_FILE);
        return;
    }

    std::remove(DATABASE_FILE);
    std::rename(TEMP_FILE, DATABASE_FILE);

    cout << "Record Removed Successfully\n";
}

// عرض المنتجات
void Shopping::list() {
    int choice;
    cout << "\nSelect Category to View Products:";
    cout << "\n1. Fruits";
    cout << "\n2. Vegetables";
    cout << "\n3. Detergents";
    cout << "\nPlease enter your choice: ";
    cin >> choice;

    string category;
    switch (choice) {
        case 1:
            category = "Fruits";
            break;
        case 2:
            category = "Vegetables";
            break;
        case 3:
            category = "Detergents";
            break;
        default:
            cout << "Invalid choice! Returning to the menu.\n";
            return;
    }

    listByCategory(category);
}

// عرض المنتجات حسب القسم
void Shopping::listByCategory(const string &category) {
    fstream data;
    data.open(DATABASE_FILE, ios::in);
    if (!data) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    cout << "\nProduct List in Category: " << category << "\n";
    cout << "Code\tName\tPrice\tDiscount\tQuantity\tCategory\n";

    while (data >> p_code >> p_name >> price >> discount >> quantity >> this->category) {
        if (this->category == category) {
            cout << p_code << "\t" << p_name << "\t" << price << "\t" << discount << "\t\t" << quantity << "\t\t" << category << endl;
        }
    }
    data.close();
}

// شراء المنتجات
void Shopping::buyer() {
    string category;
    cout << "Enter Category (e.g., Fruits, Vegetables, Detergents): ";
    cin >> category;

    listByCategory(category);

    receipt();
}

// إصدار فاتورة
void Shopping::receipt() {
    fstream data, temp;
    vector<int> codes, quantities;
    int code, quantity;
    float total = 0.0;

    // عرض قائمة المنتجات
    list();

    // إدخال الأكواد والكميات
    cout << "Enter the Product Code and Quantity (-1 to Stop):\n";
    while (true) {
        cin >> code;
        if (code == -1) break;
        cin >> quantity;
        codes.push_back(code);
        quantities.push_back(quantity);
    }

    data.open(DATABASE_FILE, ios::in);
    temp.open(TEMP_FILE, ios::out);
    if (!data || !temp) {
        cout << "Error: Unable to open file.\n";
        return;
    }

    // معالجة كل منتج مدخل
    for (size_t i = 0; i < codes.size(); i++) {
        bool found = false;

        while (data >> p_code >> p_name >> price >> discount >> quantity >> category) {
            if (p_code == codes[i]) {
                found = true;

                // التحقق من الكمية المتوفرة
                if (quantities[i] > quantity) {
                    cout << "Not enough stock for product: " << p_name << ". Available: " << quantity << endl;
                    temp << p_code << " " << p_name << " " << price << " " << discount << " " << quantity << " " << category << endl;
                    continue;
                }

                // تحديث الكمية المتوفرة
                float amount = price * quantities[i];
                float discounted_amount = amount - (amount * discount / 100);
                cout << p_code << "\t" << p_name << "\t" << price << "\t" << quantities[i] << "\t\t" << discounted_amount << endl;
                total += discounted_amount;

                quantity -= quantities[i];
            }

            // كتابة البيانات المحدثة
            temp << p_code << " " << p_name << " " << price << " " << discount << " " << quantity << " " << category << endl;
        }

        // إذا لم يتم العثور على المنتج
        if (!found) {
            cout << "Product with code " << codes[i] << " not found.\n";
        }

        // إعادة المؤشر إلى بداية الملف
        data.clear();
        data.seekg(0);
    }

    data.close();
    temp.close();

    // تحديث الملف الأصلي
    std::remove(DATABASE_FILE);
    std::rename(TEMP_FILE, DATABASE_FILE);

    cout << "Grand Total: " << total << endl;
}

// البرنامج الرئيسي
int main() {
    Shopping s;
    s.menu();
    return 0;
}
