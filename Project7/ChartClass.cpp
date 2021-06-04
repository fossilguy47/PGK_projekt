#include <wx/dc.h>
#include <memory>
#include "ChartClass.h"
#include "vecmat.h"

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

struct Segment
{
    Point mA, mB, mC;
    Segment() : mA(), mB(), mC() {}
    Segment(Point A, Point B, Point C) : mA(A), mB(B), mC(C) {}
    double sumZ() const
    {
        return mA.mZ + mB.mZ + mC.mZ;
    }
};


ChartClass::ChartClass(std::shared_ptr<ConfigClass> c, int w, int h) : _w(w), _h(h) 
{
	cfg = std::move(c);
}

void ChartClass::Draw(wxDC* dc) 
{
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	if (cfg->Get_contour())
	{
		drawContourMap(dc);
	}
	else dc->DrawText("KONTUROWA", wxPoint(100, 100));
}

double ChartClass::getFunctionValue(double x, double y)
{
	switch (cfg->Get_f_type())
	{
	case 1:
		return pow(x, 3) - pow(y, 3);
		break;
	case 2:
		return x * x + y * y;
		break;
	case 3:
		return x + 2 * y;
		break;
	case 4:
		return pow(y, 3) + 2 * x * x - 3 * y * y - 4 * x + 3 * y;
		break;
	default:
		return 50*sin((x * x + y * y)/500);
	}
}

void ChartClass::drawLine2d(wxDC* dc, Matrix t, double x1, double y1, double x2, double y2,
							double z1, double z2)
{

}

void ChartClass::drawAxes(wxDC* dc, Matrix t) {

}

void ChartClass::drawContourMap(wxDC *dc)
{
	/*wxMemoryDC memDC;
	memDC.SelectObject(memoryBitmap);
	memDC.Clear();
	memDC.SetPen(*wxBLACK_PEN);
	memDC.SetBrush(*wxWHITE_BRUSH);*/
	int w, h;
	if (cfg->Get_x1() - cfg->Get_x0() > cfg->Get_y1() - cfg->Get_y0())
	{
		w = 500;
		h = static_cast<int>((cfg->Get_y1() - cfg->Get_y0()) / (cfg->Get_x1() - cfg->Get_x0()) * w);
	}
	else if (cfg->Get_x1() - cfg->Get_x0() < cfg->Get_y1() - cfg->Get_y0())
	{
		h = 500;
		w = static_cast<int>((cfg->Get_x1() - cfg->Get_x0()) / (cfg->Get_y1() - cfg->Get_y0()) * h);
	}
	else
	{
		w = 500;
		h = 500;
	}
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(*wxBLACK_PEN));
	dc->DrawRectangle(10, 10, w - 20, h - 20);
	dc->SetClippingRegion(wxRect(10, 10, w - 20, h - 20));
	auto** valueGrid = new float* [h];
	for (int i = 0; i < h; ++i)
	{
		valueGrid[i] = new float[w];
	}

	double x_start = cfg->Get_x_start();
	double x_stop = cfg->Get_x_stop();
	double y_start = cfg->Get_y_start();
	double y_stop = cfg->Get_y_stop();
	double x_step = (x_stop - x_start) / (w-1.0);
	double y_step = (y_stop - y_start) / (h-1.0);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			valueGrid[i][j] = getFunctionValue(x_start+i*x_step, y_start+j*y_step);

	double f_min = valueGrid[0][0], f_max = valueGrid[0][0];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			f_min = valueGrid[i][j] < f_min ? valueGrid[i][j] : f_min;
			f_max = valueGrid[i][j] > f_max ? valueGrid[i][j] : f_max;
		}

	// część odpowiedzialna za kolorowanie mapy
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			const float color = (valueGrid[i][j] - f_min) / (f_max - f_min);
			//const int it = i * 500 * 3 + j * 3;
			dc->SetPen(wxColor(static_cast<int> (color * 255),
								0,static_cast<int> ((1.0 - color) * 255)));
			dc->DrawPoint(j,i);
		}
	}

	dc->SetPen(wxPen(*wxBLACK_PEN));
	int NoLevels = 5;
	for (int i = 0; i < NoLevels; i++)
	{
		float threshold = f_min + (i + 1.0) * (f_max - f_min) / (NoLevels + 1.0);

		for (int x = 0; x < w; x++)
			for (int y = 0; y < h; y++)
				if (valueGrid[y][x] > threshold)
				{
					for (int a = -1; a <= 1; a++)
						for (int b = -1; b <= 1; b++)
							if (a && b && (a + y >= 0) && (b + x >= 0) && (a + y < h) && (b + x < w) &&
								(valueGrid[a + y][b + x] < threshold))
								dc->DrawPoint(x,y);
				}
	}
	
			
	for (int i = 0; i < h; ++i)
		delete[] valueGrid[i];
	delete[] valueGrid;
}

