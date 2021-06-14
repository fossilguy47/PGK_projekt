#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include <vector>
#include "ConfigClass.h"

class Matrix;
class Vector;

struct Point
{
    double mX, mY, mZ;
    Point(double x = 0., double y = 0., double z = 0.) : mX(x), mY(y), mZ(z) {}
    Point& operator=(const Point& other)
    {
        mX = other.mX;
        mY = other.mY;
        mZ = other.mZ;
        return *this;
    }
    void operator()(double x, double y, double z) { mX = x; mY = y; mZ = z; }
};

struct Segment {
    Point begin, end;
    Segment(Point begin_point, Point end_point) : begin(begin_point), end(end_point) {}
};

class ChartClass
{
private:
    std::shared_ptr<ConfigClass> cfg;
    int _w, _h;
    int plot_w, plot_h;
    float f_max, f_min;
    std::vector<Segment> data;
    std::vector<float> valueGrid;
public:
    ChartClass(std::shared_ptr<ConfigClass> c, int w = 600, int h = 400);
    Matrix createTransformationMatrix();
    void Draw(wxDC* dc);
    void transformVector(Vector& v);
    void drawLine(wxDC* dc, Vector p0, Vector p1);
    void drawAxes(wxDC* dc);
    void drawContourMap(wxDC* dc);
    void drawChart(wxDC* dc);
    double getFunctionValue(double x, double y);
    void initializeValueGrid();
    std::vector<float> Get_valueGrid() { return valueGrid; }
    float Get_f_max() { return f_max; }
    float Get_f_min() { return f_min; }
    /* wstawi³am t¹ funkcjê do ChartClass, ale nie wiem czy nie lepiej,
     aby ta funkcja znajdowa³a siê w GUIMyFrame*/
    void drawValueBar(wxDC *dc);
    void addSegment(Segment s);
};

#endif