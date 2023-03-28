#include <iostream>
using namespace std;

class Coordinate{
public:
    int x, y;
    Coordinate(int, int);
    Coordinate(Coordinate*);
};

Coordinate::Coordinate(int _x, int _y):x(_x),y(_y){}

Coordinate::Coordinate(Coordinate *obj){
    x = -(obj->x);
    y = -(obj->y);
}

class Square{
    Coordinate **set = new Coordinate*[4];
public:
    Square(int, int, int, int);
    Square(int, int, int);
    Square(Square*);
    Square();
    Square(int);
    void Print();
};

Square::Square(int x, int y, int length, int width){
    set[0] = new Coordinate(x, y);
    set[1] = new Coordinate(x+width, y);
    set[2] = new Coordinate(x, y+length);
    set[3] = new Coordinate(x+width, y+length);
}

Square::Square(int x, int y, int radius){
    set[0] = new Coordinate(x-radius, y-radius);
    set[1] = new Coordinate(x+radius, y-radius);
    set[2] = new Coordinate(x+radius, y+radius);
    set[3] = new Coordinate(x-radius, y+radius);
}

Square::Square(Square *obj){
    set[0] = new Coordinate(obj->set[0]);
    set[1] = new Coordinate(obj->set[1]);
    set[2] = new Coordinate(obj->set[2]);
    set[3] = new Coordinate(obj->set[3]);
}

Square::Square(){
    for(int i = 0; i < 4; i++){
        set[i] = NULL;
    }
}

Square::Square(int n):Square::Square(n, n, n, n){}

void Square::Print(){
    cout << "given square has points at coordinates ";
    for(int i = 0; i < 4; i++){
        if(set[i] != NULL){
            cout << "(" << set[i]->x << ", " << set[i]->y << ") ";
        }
        else{
            cout << "NULL ";
        }
    }
    cout << endl;
}

int main(){
    cout << "input 4 int values" << endl;
    int x, y, length, width;
    cin >> x >> y >> width >> length;
    Square /*square1(),*/ square2(x, y, length, width), square3(x, y, width), square4(&square2), square5(x);
    // cout << "square1: ";
    // square1.Print();
    cout << "square2: ";
    square2.Print();
    cout << "square3: ";
    square3.Print();
    cout << "square4: ";
    square4.Print();
    cout << "square5: ";
    square5.Print();
}