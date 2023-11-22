#pragma once
#include <iostream>
#include "Rectangle.h"

class Cube :
    public Rectangle
{
public:
    Cube();
    Cube(int tcote);
    int getPerimetre();
    int getAire();
    int getCote();
    string afficheInfo();
};