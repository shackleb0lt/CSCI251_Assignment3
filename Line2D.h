
#ifndef LINE2D_H
#define LINE2D_H
#include<iostream>
#include<string.h>
#include<vector>

#include<iomanip>
#include<cmath>
#include "Point2D.h"
using namespace std;

class Line2D
{
    private:
    Point2D pt1;
    Point2D pt2;
    double length;

    public:
    Line2D(Point2D pt1=Point2D(0,0),Point2D pt2=Point2D(0,0)); //constuctor
    Point2D getPt1() const;
    Point2D getPt2() const;
    void setLength();                       //defines the length of line
    double getScalarValue() const;          //sets the length of the line

    void setPt1(Point2D pt1);
    void setPt2(Point2D pt2);

    bool operator ==(Line2D L1);            //== operator overload definition for Line2D
    double operator -(Line2D L1);           //- operator overload definition for Line2D
    friend ostream& operator<<(ostream& os, const Line2D& L);//<< operator overload definition for Line2D
};
#endif