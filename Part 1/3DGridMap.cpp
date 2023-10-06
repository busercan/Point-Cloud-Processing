//�rem Kavakp�nar
#include "3DGridMap.h"
#include<string>
#include<iostream>
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include <iterator>
using namespace std;
//koordinatlar� verilen mapi d�ndurur.
bool* GridMap::getMap(int i, int j, int k) const {

	return (map + (i * depth * depth) + (j * depth) + k);
}
//gridsize'� dondurur.
float GridMap::getGridSize() const {
	return gridSize;
}
//depthi dondurur.
int GridMap::getDepth() const {
	return depth;
}
//mapin koordinatlar�n� atar.
void GridMap::setMap(int i, int j, int k, bool value) {

	*(map + (i * depth * depth) + (j * depth) + k) = value;

}
//gridsize'� atar.
void GridMap::setGridSize(float _gridSize) {
	gridSize = _gridSize;
}
//depthi atar.
void GridMap::setDepth(int _depth) {
	depth = _depth;
}
//verilen noktalar dizisinin denk geldi�i k�p� true olarak degistirir.
void GridMap::insertPointCloud(PointCloud& pc) {
	list<Point>::iterator iter;
	list<Point> p = pc.getPoints();
	for (iter = p.begin(); iter != p.end(); iter++)
	{
		double coordX;
		double coordY;
		double coordZ;

		

		coordX = iter->getX() / gridSize;
		coordY = iter->getY() / gridSize;
		coordZ = iter->getZ() / gridSize;

		int coordx, coordy, coordz;
		if (coordX - (int)coordX == 0)
		{
			coordx = (int)coordX;
		}
		else
		{
			coordx = (int)coordX;
			coordx++;
		}
		if (coordX - (int)coordX == 0)
		{
			coordy = (int)coordY;
		}
		else
		{
			coordy = (int)coordY;
			coordy++;
		}
		if (coordX - (int)coordX == 0)
		{
			coordz = (int)coordZ;
		}
		else
		{
			coordz = (int)coordZ;
			coordz++;
		}
		*(map + (coordx * depth * depth) + (coordy * depth) + coordz) = true;
	}

}
//verilen noktan�n denk geldigi kupu true olarak degistirir.
void GridMap::insertPoint(Point& p) {
	double coordX;
	double coordY;
	double coordZ;

	coordX = p.getX() / gridSize;
	coordY = p.getY() / gridSize;
	coordZ = p.getZ() / gridSize;

	int coordx, coordy, coordz;
	if (coordX - (int)coordX == 0)
	{
		coordx = (int)coordX;
	}
	else
	{
		coordx = (int)coordX;
		coordx++;
	}
	if (coordX - (int)coordX == 0)
	{
		coordy = (int)coordY;
	}
	else
	{
		coordy = (int)coordY;
		coordy++;
	}
	if (coordX - (int)coordX == 0)
	{
		coordz = (int)coordZ;
	}
	else
	{
		coordz = (int)coordZ;
		coordz++;
	}
	*(map + (coordx * depth * depth) + (coordy * depth) + coordz) = true;

}
//koordinatlar� verilen grid'i dondurur.
bool GridMap::getGrid(int x, int y, int z) const {
	return*((map + (x * depth * depth) + (y * depth) + z));

}
//filename'i verilen dosyaya noktalar� yukler.
bool GridMap::loadMap(PointCloud pc) {
	int count = 0;
	list<Point>* P = new list<Point>;
	*P = pc.getPoints();
	Point temp;
	list<Point>::iterator iter;
	for (iter = P->begin(); iter != P->end(); iter++)
	{
		insertPoint(*iter);
	}
	return true;
	
}
//filename'i verilen dosyay� saveler.
bool GridMap::saveMap(string _fileName) {
	ofstream file;
	
	file.open(_fileName);
	file << gridSize;
	file << endl;
	file << depth;
	file << endl;
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < depth; j++)
		{
			for (int k = 0; k < depth; k++) {

				file << *(map + i * depth * depth + j * depth + k);
				file << endl;
			}
		}
	}
	return true;
}