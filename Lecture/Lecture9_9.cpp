#include <iostream>

using namespace std;

class Block {

private:     

    string color;
    float x, y;

public:
    //note these function definitions are inlined!

    void setColor(string newColor) {Block::color = newColor;}

    void setX(float newX) {Block::x =  newX;}    

    void setY(float newY) {Block::y = newY;}

    string getColor()   { return color; }
    float getX() { return x; }
    float getY() { return y; }

  
    void display();
    void moveRight(float units);
    
};

void Block::display() {
    cout << color << "(" << Block::x << "," << Block::y << ")" << endl;
}

void Block::moveRight(float units) {
    Block::x += units;
}

int main()
{
    Block b1;

    //make the color  “Red"
    b1.setColor("Red");

    //make X equal to 1.2
    b1.setX(1.2);

    //make Y equal to 2.4
    b1.setY(2.4);

    b1.display();


    do {

        b1.display();

        b1.moveRight(4);

    } while ( b1.getX() < 12); //while the x value is on screen

   return 0;
}