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

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c, int w, int h) : _w(w), _h(h) {
	cfg = std::move(c);
}

void ChartClass::Draw(wxDC* dc) {
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	if (cfg->Get_contour()) dc->DrawText("KONTUROWA", wxPoint(100, 100));
	else
	{
		//dc->DrawText("NIEKONTUROWA", wxPoint(100, 100));

	}
}

void ChartClass::drawLine2d(wxDC* dc, Matrix t, double x1, double y1, double x2, double y2) {

}

void ChartClass::drawAxes(wxDC* dc, Matrix t) {

}

