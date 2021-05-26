#ifndef POINT3D_H
#define POINT3D_H

#include<iostream>
#include<string.h>
#include<iomanip>
#include<cmath>
using namespace std;
class Point3D
{
    private:
    int x,y,z;
    double distFrOrigin;

    public:
    Point3D(int a=0,int b=0,int c=0);   //constructor method
    
    int getX() const;                   //returns x
    int getY() const;                   //returns y
    int getZ() const;                   //returns z

    void setDistFrOrigin();             //defines the distance from origin
    double getScalarValue() const;      //returns distance from origin
    

    void setX(int a);                   //defines x 
    void setY(int b);                   //defines y
    void setZ(int c);                   //defines z

    bool operator ==(Point3D pt1);      //== operator overload definition for Point3D
    double operator -(Point3D pt1);     //- operator overload definition for Point3D
    friend ostream& operator<<(ostream& os, const Point3D& pt); //<< operator overload definition for Point3D

};

#endif