#include <wx/dc.h>
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

std::vector<Segment> ChartClass::getAxes(wxDC* dc) {
	std::vector<Segment> axes;
	axes.clear();
	axes.push_back(Segment(Point(0, 0, 0), Point(150, 0, 0)));
	axes.push_back(Segment(Point(0, 0, 0), Point(0, 150, 0)));
	axes.push_back(Segment(Point(0, 0, 0), Point(0, 0, 200)));
	return axes;
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

void ChartClass::drawLine2d(wxDC* dc, Matrix t, double x1, double y1, double x2, double y2,
							double z1, double z2)
{

}

void ChartClass::drawAxes(wxDC* dc) {
	dc->SetBackground(wxBrush(RGB(255, 255, 255)));
	dc->SetTextForeground(wxColour(0,0,0));
	dc->Clear();
	dc->SetPen(wxPen(RGB(0, 0, 0)));

	//Macierz transformacji
	Matrix T = createTransformationMatrix();
	//Dodatkowa macierz translacji, umieszczajaca obiekt w centrum panelu - połowa wysokości i szerokości
	Matrix C;
	C.data[0][0] = 1;
	C.data[1][1] = 1;
	C.data[2][2] = 1;
	C.data[0][3] = 0.5;
	C.data[1][3] = 0.5;

	////PÓKI CO W DATA SĄ TYLKO OSIE (w podobny sposób bedzie chyba wykres najłatwiej zrobić)
	std::vector<Segment> data = getAxes(dc);
	//For przechodzacy przez wszystkie rysowane odcinki
	for (auto& line : data) {
		//Poczatkowy i koncowy punkt odcinka
		Vector p0, p1;
		//Ustawienie punktu p0owego i koncowego odcinka
		p0.Set(line.begin.mX, line.begin.mY, line.begin.mZ);
		p1.Set(line.end.mX, line.end.mY, line.end.mZ);
		//Przemonozenie obu punktów przez macierze transformacji
		p0 = T * p0;
		p1 = T * p1;
		//Rzutowanie punktów na płaszczyznę ekranu, "spłaszczenie" osi Z
		p0.Set(p0.GetX() / p0.GetZ(), p0.GetY() / p0.GetZ(), p0.GetZ());
		p1.Set(p1.GetX() / p1.GetZ(), p1.GetY() / p1.GetZ(), p1.GetZ());
		//Dodatkowa translacja określająca środek ekranu
		p0 = C * p0;
		p1 = C * p1;
		dc->DrawLine(p0.GetX() * _w, p0.GetY() * _h, p1.GetX() * _w, p1.GetY() * _h);
	}
	dc->SetPen(wxPen(RGB(0, 0, 0)));
	Vector x_text, y_text, z_text;
	x_text.Set(150, -10, 0);
	y_text.Set(-10, 150, 0);
	z_text.Set(10, 0, 200);
	x_text = T * x_text;
	y_text = T * y_text;
	z_text = T * z_text;
	x_text.Set(x_text.GetX() / x_text.GetZ(), x_text.GetY() / x_text.GetZ(), x_text.GetZ());
	y_text.Set(y_text.GetX() / y_text.GetZ(), y_text.GetY() / y_text.GetZ(), y_text.GetZ());
	z_text.Set(z_text.GetX() / z_text.GetZ(), z_text.GetY() / z_text.GetZ(), z_text.GetZ());
	x_text = C * x_text;
	y_text = C * y_text;
	z_text = C * z_text;
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

	// skalowanie mapy konturowej
	// kiedy długość > szerokość
	if (cfg->Get_x1() - cfg->Get_x0() > cfg->Get_y1() - cfg->Get_y0())
	{
		w = 500;
		h = static_cast<int>((cfg->Get_y1() - cfg->Get_y0()) / (cfg->Get_x1() - cfg->Get_x0()) * w);
	}
	// kiedy szerokość > długość
	else if (cfg->Get_x1() - cfg->Get_x0() < cfg->Get_y1() - cfg->Get_y0())
	{
		h = 500;
		w = static_cast<int>((cfg->Get_x1() - cfg->Get_x0()) / (cfg->Get_y1() - cfg->Get_y0()) * h);
	}
	// kiedy długość == szerokość
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

	double x0 = cfg->Get_x0();
	double x1 = cfg->Get_x1();
	double y0 = cfg->Get_y0();
	double y1 = cfg->Get_y1();
	double x_step = (x1 - x0) / (w-1.0);
	double y_step = (y1 - y0) / (h-1.0);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			valueGrid[i][j] = getFunctionValue(x0+i*x_step, y0+j*y_step);

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

	// kontury (póki co ustawione na 5 poziomic)
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
	/*std::vector<float> valueGrid;
	valueGrid.clear();

	double x_start = cfg->Get_x_start();
	double x_stop = cfg->Get_x_stop();
	double y_start = cfg->Get_y_start();
	double y_stop = cfg->Get_y_stop();
	double x_step = (x_stop - x_start) / (w - 1.0);
	double y_step = (y_stop - y_start) / (h - 1.0);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			valueGrid.push_back(getFunctionValue(x_start + i * x_step, y_start + j * y_step));

	double f_min = valueGrid[0], f_max = valueGrid[0];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
		{
			f_min = valueGrid[w*i+j] < f_min ? valueGrid[w*i+j] : f_min;
			f_max = valueGrid[w*i+j] > f_max ? valueGrid[w*i+j] : f_max;
		}

	// część odpowiedzialna za kolorowanie mapy
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			const float color = (valueGrid[w*i+j] - f_min) / (f_max - f_min);
			//const int it = i * 500 * 3 + j * 3;
			dc->SetPen(wxColor(static_cast<int> (color * 255),
				0, static_cast<int> ((1.0 - color) * 255)));
			dc->DrawPoint(j, i);
		}
	}

	// kontury (póki co ustawione na 5 poziomic)
	dc->SetPen(wxPen(*wxBLACK_PEN));
	int NoLevels = 5;
	for (int i = 0; i < NoLevels; i++)
	{
		float threshold = f_min + (i + 1.0) * (f_max - f_min) / (NoLevels + 1.0);

		for (int x = 0; x < w; x++)
			for (int y = 0; y < h; y++)
				if (valueGrid[w*y+x] > threshold)
				{
					for (int a = -1; a <= 1; a++)
						for (int b = -1; b <= 1; b++)
							if (a && b && (a + y >= 0) && (b + x >= 0) && (a + y < h) && (b + x < w) &&
								(valueGrid[w*(a + y)+b + x] < threshold))
								dc->DrawPoint(x, y);
				}
	}*/
}

