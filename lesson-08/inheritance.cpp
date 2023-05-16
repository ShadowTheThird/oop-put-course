#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Product{
protected:
    string name;
    double price;
    int product_id;
public:
    Product(string _name, double _price, int _id):name(_name), price(_price), product_id(_id){}
    double Price(){
        return price;
    }
};

class Customer{
protected:
    string name, email;
    int customer_id;
public:
    Customer(string _name, string _email, int _id):name(_name), email(_email), customer_id(_id){}
    string Name(){
        return name;
    }
};

class Order{
protected:
    Customer customer;
    vector<Product> cart;
    int order_id;
public:
    Order(Customer _customer, int _id):customer(_customer), order_id(_id){}
    void AddProduct(Product product){
        cart.push_back(product);
    }
    string CustomerName(){
        return customer.Name();
    }
    double Calculate(){
        double sum = 0;
        for(int i = 0; i < cart.size(); i++){
            sum += cart[i].Price();
        }
        return sum;
    }
};

int main(){
    Product milk("milk", 12.5, 301), sandwich("sandwich", 17.33, 202), icecream("icecream", 72.85, 7313);
    Customer John("John", "john.masuali@gmail.com", 22), Robert("Robert", "robert.smith@gmail.com", 7);
    Order order7(John, 7), order3(Robert, 3);
    order7.AddProduct(milk);
    order7.AddProduct(icecream);
    order3.AddProduct(sandwich);
    order3.AddProduct(sandwich);
    cout << order7.CustomerName() << " has " << order7.Calculate() << " worth of products in the cart" << endl;
    cout << order3.CustomerName() << " has " << order3.Calculate() << " worth of products in the cart" << endl;
}