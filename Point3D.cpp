#include "Point3D.h"

//POint3D definitions
Point3D::Point3D(int a,int b,int c){x=a;y=b;z=c; setDistFrOrigin();}

int Point3D::getX()const{return x;}
int Point3D::getY()const{return y;}
int Point3D::getZ()const{return z;}

void Point3D::setDistFrOrigin(){distFrOrigin = sqrt((x*x)+(y*y)+(z*z)) ;}
double Point3D::getScalarValue()const{return distFrOrigin;}

void Point3D::setX(int a){ x=a;}
void Point3D::setY(int b){ y=b;}
void Point3D::setZ(int c){ z=c;}

bool Point3D::operator ==(Point3D pt1)
{
    if(pt1.getX()!=getX())return false;
    else if(pt1.getY()!=getY())return false;
    else if(pt1.getZ()!=getZ())return false;
    return true;
}
double Point3D::operator-(Point3D pt1)
{
    return abs(getScalarValue()-pt1.getScalarValue());
}

ostream& operator<<(ostream& os, const Point3D& pt)
{
    os << "[" << std::right << std::setfill(' ') << std::setw(4) << pt.getX()<<","
                                                 << std::setw(4) << pt.getY()<<","
                                                 << std::setw(4) << pt.getZ()<<"]   "
              << std::left << std::setfill(' ')  << std::fixed << std::setprecision(3) << pt.getScalarValue()<<endl;
    return os;
}
