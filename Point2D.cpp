#include "Point2D.h"
//Point2D definitions

Point2D::Point2D(int x,int y):Point3D(x,y,0){Point2D::setDistFrOrigin();}
void Point2D::setDistFrOrigin(){Point3D::setDistFrOrigin();}

bool Point2D::operator ==(Point2D pt1)
{
    if(pt1.getX()!=getX())return false;
    else if(pt1.getY()!=getY())return false;
    return true;
}
double Point2D::operator-(Point2D pt1)
{
    return abs(getScalarValue()-pt1.getScalarValue());
}

ostream& operator<<(ostream& os, const Point2D& pt)
{
    os << "[" << std::right << std::setfill(' ') << std::setw(4) << pt.getX()<<","
                                                 << std::setw(4) << pt.getY()<<"]   "
              << std::left << std::setfill(' ')  << std::fixed << std::setprecision(3) << pt.getScalarValue()<<endl;
    return os;
}

