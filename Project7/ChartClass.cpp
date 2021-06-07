#include <wx/dc.h>
#include <memory>
#include "ChartClass.h"
#include "vecmat.h"
#define PI 3.14159

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
	Segment(Point begin_point, Point end_point) : begin(begin_point), end(end_point){}
};

//struct Segment
//{
//    Point mA, mB, mC;
//    Segment() : mA(), mB(), mC() {}
//    Segment(Point A, Point B, Point C=Point(0,0,0)) : mA(A), mB(B), mC(C) {}
//    double sumZ() const
//    {
//        return mA.mZ + mB.mZ + mC.mZ;
//    }
//};


ChartClass::ChartClass(std::shared_ptr<ConfigClass> c, int w, int h) : _w(w), _h(h) 
{
	cfg = std::move(c);
}


Matrix createRotationMatrix(double Rx, double Ry, double Rz) {
	//Macierze rotacji wokół osi X, Y, Z
	Matrix R_X, R_Y, R_Z;
	//Wypelniamy macierze zgodnie ze schematem zaprezentowanym na wykładzie
	R_X.data[0][0] = 1;
	R_X.data[1][1] = cos(Rx * PI / 180);
	R_X.data[1][2] = -sin(Rx * PI / 180);
	R_X.data[2][1] = sin(Rx * PI / 180);
	R_X.data[2][2] = cos(Rx * PI / 180);

	R_Y.data[0][0] = cos(Ry * PI / 180);
	R_Y.data[0][2] = sin(Ry * PI / 180);
	R_Y.data[1][1] = 1;
	R_Y.data[2][0] = -sin(Ry * PI / 180);
	R_Y.data[2][2] = cos(Ry * PI / 180);

	R_Z.data[0][0] = cos(Rz * PI / 180);
	R_Z.data[0][1] = -sin(Rz * PI / 180);
	R_Z.data[1][0] = sin(Rz * PI / 180);
	R_Z.data[1][1] = cos(Rz * PI / 180);
	R_Z.data[2][2] = 1;

	//Zwracamy iloczyn odpowiadający kolejnym transformacjom w 3 wymiarach
	return R_X * R_Y * R_Z;
}

Matrix ChartClass::createTransformationMatrix() {
	//wartosci zmian x y z odpowiednio do translacji, rotacji, skalowania
	double Tx, Ty, Tz, Rx, Ry, Rz, Sx, Sy, Sz;
	//ustawienie odpowiednich wartosci parametrow

	////TU WSTAWIĆ PRAWIDŁOWE PARAMETRY
	Tx = 0.0;
	Ty = 0.0;
	Tz = 2.0;
	Rx = 45 + cfg->Get_x_rot() * 360.0 / 100.0;
	Ry = 0 + cfg->Get_y_rot() * 360.0 / 100.0;
	Rz = 135 + cfg->Get_z_rot() * 360.0 / 100.0;
	Sx = (cfg->Get_zoom()/50.0) / 100.0;
	Sy = (cfg->Get_zoom() / 50.0) / 100.0;
	Sz = (cfg->Get_zoom() / 50.0) / 100.0;

	//macierze przeksztalcen odpowiednio translacji, rotacji, skalowania
	Matrix T, R, S;
	//macierz translacji, T[3][3] juz wypelnione
	T.data[0][0] = 1;
	T.data[1][1] = 1;
	T.data[2][2] = 1;
	T.data[0][3] = Tx;
	T.data[1][3] = -Ty;
	T.data[2][3] = Tz;
	//uzupelnienie macierzy rotacji przy wykorzystaniu osobnej funkcji
	R = createRotationMatrix(Rx, Ry, Rz);
	//macierz skalowania
	S.data[0][0] = Sx;
	S.data[1][1] = -Sy;
	S.data[2][2] = Sz;

	return T * R * S;
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
	else 
	{
		drawAxes(dc);
		drawChart(dc);
	}
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

void ChartClass::transformVector(Vector& v)
{
	//Macierz transformacji
	Matrix T = createTransformationMatrix();
	//Dodatkowa macierz translacji, umieszczajaca obiekt w centrum panelu - połowa wysokości i szerokości
	Matrix C;
	C.data[0][0] = 1;
	C.data[1][1] = 1;
	C.data[2][2] = 1;
	C.data[0][3] = 0.5;
	C.data[1][3] = 0.5;

	//Przemonozenie obu punktów przez macierze transformacji
	v = T * v;
	//Rzutowanie punktów na płaszczyznę ekranu, "spłaszczenie" osi Z
	v.Set(v.GetX() / v.GetZ(), v.GetY() / v.GetZ(), v.GetZ());
	//Dodatkowa translacja określająca środek ekranu
	v = C * v;
}

void ChartClass::drawLine(wxDC* dc, Vector p0, Vector p1)
{
	transformVector(p0);
	transformVector(p1);
	dc->DrawLine(p0.GetX() * _w, p0.GetY() * _h, p1.GetX() * _w, p1.GetY() * _h);
}

void ChartClass::drawAxes(wxDC* dc) {
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->SetTextForeground(wxColour(0,0,0));
	dc->Clear();
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	//Poczatkowy i koncowy punkt odcinka
	Vector p0, x1, y1, z1;
	//Ustawienie punktu p0owego i koncowego odcinka
	p0.Set(0,0,0);
	x1.Set(150,0,0);
	y1.Set(0, 150, 0);
	z1.Set(0, 0, 200);
	drawLine(dc, p0, x1);
	drawLine(dc, p0, y1);
	drawLine(dc, p0, z1);
	//Text osi
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	Vector x_text, y_text, z_text;
	x_text.Set(150, -10, 0);
	y_text.Set(-10, 150, 0);
	z_text.Set(10, 0, 200);
	transformVector(x_text);
	transformVector(y_text);
	transformVector(z_text);
	dc->DrawText("X", wxPoint(x_text.GetX() * _w, x_text.GetY() * _h));
	dc->DrawText("Y", wxPoint(y_text.GetX() * _w, y_text.GetY() * _h));
	dc->DrawText("Z", wxPoint(z_text.GetX() * _w, z_text.GetY() * _h));
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

void ChartClass::drawChart(wxDC* dc)
{
	double step = 2;
	double x0 = cfg->Get_x0();
	double x1 = cfg->Get_x1();
	double y0 = cfg->Get_y0();
	double y1 = cfg->Get_y1();
	int i, j;
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	for (i = 0; i < (x1-x0)/step ; i++)
	{
		for (j = 0; j < (y1 - y0) / step; j++)
		{
			Vector p0, p1, p2;
			//Ustawienie punktu początkowego i koncowego odcinka
			p0.Set(x0 + step * i, y0 + step * j, getFunctionValue(x0 + step * i, y0 + step * j));
			p1.Set(x0 + step * (i+1), y0 + step * j, getFunctionValue(x0 + step * (i + 1), y0 + step * j));
			p2.Set(x0 + step * i, y0 + step * (j + 1), getFunctionValue(x0 + step * i, y0 + step * (j + 1)));
			//Rysowanie połączenia w prawym i dolnym punktem
			drawLine(dc, p0, p1);
			drawLine(dc, p0, p2);
		}
	}
	int i_max = i;
	int j_max = j;
	//Dorysowanie skrajnych linii na wykresie
	for (i = 0; i < (x1 - x0) / step; i++)
	{
		Vector p0, p1;
		//Ustawienie punktu początkowego i koncowego odcinka
		p0.Set(x0 + step * i, y0 + step * j_max, getFunctionValue(x0 + step * i, y0 + step * j_max));
		p1.Set(x0 + step * (i + 1), y0 + step * j_max, getFunctionValue(x0 + step * (i + 1), y0 + step * j_max));
		//Rysowanie połączenia w prawym i dolnym punktem
		drawLine(dc, p0, p1);
	}
	for (j = 0; j < (y1 - y0) / step; j++)
	{
		Vector p0, p1;
		//Ustawienie punktu początkowego i koncowego odcinka
		p0.Set(x0 + step * i_max, y0 + step * j, getFunctionValue(x0 + step * i_max, y0 + step * j));
		p1.Set(x0 + step * i_max, y0 + step * (j + 1), getFunctionValue(x0 + step * i_max, y0 + step * (j+1)));
		//Rysowanie połączenia w prawym i dolnym punktem
		drawLine(dc, p0, p1);
	}
}


