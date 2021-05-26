#ifndef POINT2D_H
#define POINT2D_H

#include<iostream>
#include<string.h>
#include<iomanip>
#include<cmath>
#include"Point3D.h"

using namespace std;
class Point2D: public Point3D           //Point2D inherits from Point3d
{
    public:
    Point2D(int x=0,int y=0);
    void setDistFrOrigin();

    bool operator ==(Point2D pt1);      //== operator overload definition for Point2D
    double operator -(Point2D pt1);     //- operator overload definition for Point2D
    friend ostream& operator<<(ostream& os, const Point2D& pt);//<< operator overload definition for Point2D
};
#endif 