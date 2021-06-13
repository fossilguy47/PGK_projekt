#pragma warning(disable: 4996)
#include <fstream>
#include "ConfigClass.h"

using namespace std;

ConfigClass::ConfigClass(GUIMyFrame* wnd)
{
    MainWindow = wnd;
    is_contour = false;
    x_start = -50.0;
    x_stop = 50.0;
    y_start = -50.0;
    y_stop = 50.0;
    f_type = 0;
    x0 = -50.0;
    y0 = -50.0;
    z0 = -50.0;
    x1 = 50.0;
    y1 = 50.0;
    z1 = 50.0;
    zoom = 50.0;
    x_rot = 13;
    y_rot = 0.0;
    z_rot = 38;
    x_step = 10;
    y_step = 10;
}
