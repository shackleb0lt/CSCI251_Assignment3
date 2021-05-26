
#ifndef LINE_3D
#define LINE_3D
#include<iostream>
#include<string.h>
#include<vector>
#include<iomanip>
#include<cmath>

#include "Point3D.h"

using namespace std;
class Line3D
{
    private:
    Point3D pt1;
    Point3D pt2;
    double length;
    
    public:
    Line3D(Point3D pta=Point3D(0,0,0),Point3D ptb=Point3D(0,0,0)); //constructor
    Point3D getPt1() const;
    Point3D getPt2() const;
    void setLength();                       //defines the length of line
    double getScalarValue() const;          //sets the length of the line

    void setPt1(Point3D pt);
    void setPt2(Point3D pt);

    bool operator ==(Line3D L1);            //== operator overload definition for Line3D
    double operator -(Line3D L1);           //- operator overload definition for Point3D
    friend ostream& operator<<(ostream& os, const Line3D& L); //<< operator overload definition for Point3D
};

#endif