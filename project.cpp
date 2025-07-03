#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <limits>
using namespace std;
#define PATH "D:/codes/C++_A/Data/data-base.txt"
#define COPY "D:/codes/C++_A/Data/data-temp.txt"
struct product
{
    float price;
    int quantity;
    string name;
    string category;
    int code;
};



vector<product>products;
vector<product>cart;
string password;
string currentrole;

void loadproduct(){
    product product;
    ifstream  file(PATH);
    if(file.is_open()){
        while(file>>product.code>>product.name>>product.price>>product.quantity>>product.category){
            products.push_back(product);

        }
    }else{
        cout<<"erro to open file\n";
    }

 file.close();
}
void display_product(){
  product product;
  cout<<"product code: "<<product.code
  <<"product name: "<<product.name
  <<"product price: "<<product.price
  <<"product quanity:"<<product.quantity
  <<"product category: "<<product.category<<endl;

}

void edit_product(){
    string nameproduct;
    bool isfound =false;
    cin>>nameproduct;
    for(const auto &product:products){
        if(product.name==nameproduct){
            isfound=true;
            cout<<"edit product: "<<product.name
            <<"current price: "<<product.price
            <<"product category: "<<product.category
            <<"product quantity: "<<product.quantity<<endl;
             savedproduct();
            cout<<"updated susesfule";
            break;
        }
    }
    if(!isfound){
        cout<<"product is not found\n";
    }
}
void add_product(){
    product product;
    cout<<"product code:"<<product.code
    <<"product name:"<<product.name
    <<"product price:"<<product.price
    <<"product quantoty:"<<product.quantity
    <<"product category:"<<product.category<<endl;
    savedproduct();
    cout<<"saved sucsecfuly\n";
}

 void savedproduct(){
      ofstream file(PATH);
      if(file.is_open()){
        for(const auto &product:products){
            file<<product.code<<" "<<product.name <<" "
            <<product.price<<" "<<product.quantity<<" "
            <<product.category<<endl;
        }
        file.close();
      }
 }
void login(){
    string username;
    string password;
    int choise;
    
    
    cout<<"1:Admin\n";
    cout<<"2:buyer\n";
    cout<<"enter to the choise\n";
   cin>>choise;
   switch(choise){
     case 1:
     cout<<"enter username: \n";
     cin>>username;

     if(username =="admin"){
        string adminpass="admin123";
        cout<<"Enter password";
        password.clear();
       
       char ch;

       while(true){
        ch=_getch();
        if(ch ==13){
            break;
        }else if(ch ==8){
            if(password.length() > 0){
                password.pop_back();
                cout<<"\b \b";
            }
            }
            else{
                password +=ch;
                cout<<"*";
            }
        }

        cout<<endl;

        if(password ==adminpass){
            cout<<"login sucesfuly\n";
             addmenueof_admin();

        }
        else{
            cout<<"invaled password\n";
        }
       }
       else{
        cout<<"invaled useername or password\n";
       }
   case 2:
   cout<<"hello buyer\n";
    menuebuyer();
   break;
default:
cout<<"incorect choise";
break;

       }

   }
void Viewsale_report(){
    string line;
    double totalsale;
    ifstream file(COPY);
    if(!file.is_open()){
        cout<<"error to open file\n";
    }
    while(getline(file,line)){
        size_t pos =line.find("total:");
        double saletotal =stod(line.substr(pos+6));
        totalsale +=saletotal;
    }
    cout<<"total:"<<totalsale<<endl;
    file.close();

}
void delet_product(){
    string nameproduct;
    cin>>nameproduct;
    bool isfound=false;
    for(auto it =products.begin();it !=products.end();it++){
        if(it ->name == nameproduct){
            isfound =true;
            products.erase(it);
            cout<<"product is deleted\n";
            break;
        }
    }
    if(isfound){
        cout<<" product is found!";
    }else{
        cout<<"product is not found\n";
    }
}
void addmenueof_admin(){
    cout<<"menu of admin\n";
    cout<<"1.add product\n";
    cout<<"2.edit product\n";
    cout<<"3.veiw product\n";
    cout<<"4.delet product\n";
    cout<<"5. veiw sale report\n";
    cout<<"6.logout\n";
    string choise;
    cin>>choise;
    while(true){
    if(choise == "1"){
         add_product();
    }else if(choise =="2"){
         edit_product();
    }else if(choise =="3"){
        display_product();
    }else if(choise =="4"){
         delet_product();
    }else if(choise =="5"){
         Viewsale_report();
    }else if( choise =="6"){
        cout<<"loge out\n";
        break;
    }else{
        cout<<"invaled choise\n";
    }

}    
}
void add_cart(){
    int quantity1;
    string nameproduct;
    bool is_found=false;
    cout<<"enter product\n";
    cin>>nameproduct;
    for(auto &product :products){
        if(product.name==nameproduct){
            is_found true;
            break;
            
        }
    }
    if(!is_found){
        cout<<"is not found\n";
        return;
    }

    while (true)
    {
        cout<<"enter quantity\n";
        cin>>quantity1;
        for(auto &product:products){
            if(product.name == nameproduct){
                if(product.quantity ==quantity1){
                    product ceritem =product;
                    ceritam.quantity =quantity1;
                    cart.push_back(ceritam);
                    product.quantity -=quantity1;
                    savedproduct();
                    cout<<"product addsuccesfulty\n";
                    return;
                }else{
                    cout<<"quantity is not available\n";
                    return;
                }
            }
        }
    }
    
}


void veiwcart(){
    cout<<"shoping carts\n";
    double total =0.0;
    for(auto &product:products){
         cout<<"product Name:"<<product.name
         <<"product price:"<<product.quantity<<endl;
         total =product.quantity *product.quantity;
         
    }
    cout<<"total: "<<total<<endl;


}
void complet_purchase(){
    veiwcart();
    ofstream file(COPY,ios::app);
    if(file.is_open()){
        double total=0.0;
        for(auto &product:products){
            file<<product.name<<" "<<product.price
            <<product.quantity<<" "<<product.category
            <<endl;
            total +=product.quantity *product.price;
        }
        file<<"total : "<<total<<endl;
        file.close();
    }
    file.clear();
    cout<<"purchase completed sucsecfulty\n";

}

void  menuebuyer(){
    cout<<"enter the state\n";
    cout<<"1.view product\n";
    cout<<"2.add to chart\n";
    cout<<"3. view chart\n";
    cout<<"4.complet to purchase\n";
    cout<<"5.back to main Menue\n";
    cout<<"enter the choise\n";
    int choise;
    cin>>choise;
    switch(choise){
        case 1:
         display_product();
        break;
        case 2:
         add_cart();
        break;
        case 3:
         veiwcart();
        break;

        case 4:
         complet_purchase();
        break;
        case 5:
        cout<<"login...\n";
        return;
       default:
       cout<<"invaled choise..\n";
       break;
       
    }
}

int main(){
loadproduct();
string choise;
while (true)
{
    cout<<"welcome to the online supermarket\n";
    cout<<"1.login\n";
    cout<<"Exit\n";
    cin>>choise;
    if(choise =="1"){
        login();
    }else if(choise=="2"){
        cout<<"Exit...\n";
        break;
    }else{
        cout<<"invaled choise...\n";
    }

}


}