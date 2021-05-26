#include "Line3D.h"
//Line3D definitions
Line3D::Line3D(Point3D pta,Point3D ptb):pt1(pta),pt2(ptb){setLength();}

Point3D Line3D::getPt1()const{return pt1;}
Point3D Line3D::getPt2()const{return pt2;}

void Line3D::setLength()
{
    int x=getPt1().getX()-getPt2().getX();
    int y=getPt1().getY()-getPt2().getY();
    int z=getPt1().getZ()-getPt2().getZ();
    length= sqrt((x*x) +(y*y)+(z*z));
}
double Line3D::getScalarValue()const{return length;}

void Line3D::setPt1(Point3D pt){pt1 = pt;}
void Line3D::setPt2(Point3D pt){pt2 = pt;}

bool Line3D::operator ==(Line3D L1)
{
    if(!(L1.getPt1()==getPt1()))return false;
    else if(!(L1.getPt2()==getPt2()))return false;
    return true;
}
double Line3D::operator-(Line3D L1)
{
    return abs(getScalarValue()-L1.getScalarValue());
}

ostream& operator<<(ostream& os, const Line3D& L)
{
    os << "[" << std::right << std::setfill(' ') << std::setw(4) << L.getPt1().getX()<<","
                                                 << std::setw(4) << L.getPt1().getY()<<","
                                                 << std::setw(4) << L.getPt1().getZ()<<"]   ["
                                                 << std::setw(4) << L.getPt2().getX()<<","
                                                 << std::setw(4) << L.getPt2().getY()<<","
                                                 << std::setw(4) << L.getPt2().getZ()<<"]   "


              << std::left << std::setfill(' ')  << std::fixed <<std::setprecision(3) << L.getScalarValue()<<endl;
    return os;
}