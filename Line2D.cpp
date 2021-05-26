#include "Line2D.h"
//Line2D definitions
Line2D::Line2D(Point2D pt1,Point2D pt2):pt1(pt1),pt2(pt2){Line2D::setLength();}

Point2D Line2D::getPt1()const{return pt1;}
Point2D Line2D::getPt2()const{return pt2;}

void Line2D::setPt1(Point2D pt){pt1=pt;}
void Line2D::setPt2(Point2D pt){pt2=pt;}

double  Line2D::getScalarValue()const{return length;}
void Line2D::setLength()
{
    int x=pt1.getX()-pt2.getX();
    int y=pt1.getY()- pt2.getY();
    length =sqrt((x*x)+(y*y));
}
bool Line2D::operator ==(Line2D L1)
{
    if(!(L1.getPt1()==getPt1()))return false;
    else if(!(L1.getPt2()==getPt2()))return false;
    return true;
}
double Line2D::operator-(Line2D L1)
{
    return abs(getScalarValue()-L1.getScalarValue());
}

ostream& operator<<(ostream& os, const Line2D& L)
{
    os << "[" << std::right << std::setfill(' ') << std::setw(4) << L.getPt1().getX()<<","
                                                 << std::setw(4) << L.getPt1().getY()<<"]   ["
                                                 << std::setw(4) << L.getPt2().getX()<<","
                                                 << std::setw(4) << L.getPt2().getY()<<"]   "


              << std::left << std::setfill(' ')  <<std::fixed<< std::setprecision(3) << L.getScalarValue()<<endl;
    return os;
}