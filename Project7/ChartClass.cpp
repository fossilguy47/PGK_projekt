#include <wx/dc.h>
#include <memory>
#include "ChartClass.h"
#include "vecmat.h"

ChartClass::ChartClass(std::shared_ptr<ConfigClass> c, int w, int h) : _w(w), _h(h) {
	cfg = std::move(c);
}

void ChartClass::Draw(wxDC* dc) {
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->Clear();
	dc->SetPen(wxPen(RGB(255, 0, 0)));
	dc->DrawRectangle(50, 50, _w - 100, _h - 100);
	dc->SetClippingRegion(wxRect(10, 10, _w - 20, _h - 20));
	dc->SetPen(wxPen(RGB(0, 0, 255)));
	Matrix transformation;

	drawAxis(dc, transformation);
}

void ChartClass::drawAxis(wxDC* dc, Matrix t) {
	drawLine2d(dc, t, 0, 0, 300, 0);
	drawLine2d(dc, t, 0, 0, 0, 300); 
}

void ChartClass::drawLine2d(wxDC* dc, Matrix t, double x1, double y1, double x2, double y2) {
	Vector startPoint, endPoint;
	startPoint.Set(x1, y1);
	endPoint.Set(x2, y2);
	//startPoint = t* startPoint;
	//endPoint = t * endPoint; 
	dc->DrawLine(startPoint.GetX(), _h - startPoint.GetY(), endPoint.GetX(), _h - endPoint.GetY());
}
