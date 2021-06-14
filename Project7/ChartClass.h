#ifndef __ChartClass__
#define __ChartClass__

#include <memory>
#include <vector>
#include "ConfigClass.h"

class Matrix;
class Vector;



class ChartClass
{
private:
    std::shared_ptr<ConfigClass> cfg;
    std::vector<Segment> loaded_data;
    int _w, _h;
    int plot_w, plot_h;
    float f_max, f_min;
    std::vector<float> valueGrid;
public:
    ChartClass(std::shared_ptr<ConfigClass> c, int w = 600, int h = 400, std::vector<Segment> data=std::vector<Segment>());
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
    /* wstawi�am t� funkcj� do ChartClass, ale nie wiem czy nie lepiej,
     aby ta funkcja znajdowa�a si� w GUIMyFrame*/
    void drawValueBar(wxDC *dc);;
};

#endif