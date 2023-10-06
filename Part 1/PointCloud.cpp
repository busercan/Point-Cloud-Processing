// �rem Kavakp�nar 18.12.2021
#include "PointCloud.h"
#include <iostream>
#include <iomanip>
#include <iterator>
using namespace std;
//point number initialize edildi.
PointCloud::PointCloud()
{

}

//point number� dondurur
int PointCloud::getpointNumber() const {
	return points.size();
}

void PointCloud::�nsertPoints(Point p)
{
	points.push_back(p);
}
//istenilen noktay� dondurur
std::list<Point> PointCloud::getPoints() const{
	return points;
}
//verilen pointi this->pointse atar.
void PointCloud::setPoints (list<Point> P) {

	points.clear();
	points = P;
}
//pointi verilen p vekt�r�ne esitler
void PointCloud::setPointsvector(list<Point> p)
{
	points = p;
}
//pointleri bast�r�r.
void PointCloud::Print_points(list<Point> p) {
	list<Point>::iterator it;
	for (it = p.begin(); it != p.end(); ++it)
		cout << '\t' << &it;
}
//verilen noktalar�n toplanmas�
PointCloud PointCloud::operator+(const PointCloud& pc) {
	
	PointCloud sumPC;
	sumPC = *this;

	std::list<Point> temp = pc.getPoints();
	for (int i = 0; i < pc.getpointNumber(); i++)
	{
		sumPC.�nsertPoints(temp.front());
		temp.pop_front();
	}

	return sumPC;
}
const PointCloud& PointCloud::operator=(const PointCloud& pc)
{
	if (pc.getpointNumber() == 0)
	{
		return pc;
	}
	std::list<Point> temp = pc.getPoints();
	
	if (&pc != this)
	{
		points.clear();
		for (int i = 0; i < pc.getpointNumber(); i++)
		{
			this->�nsertPoints(temp.front());
			temp.pop_front();
		}
	}

	return *this;
}