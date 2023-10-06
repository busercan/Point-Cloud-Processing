/*
* @file 3DGridMap.h
* @Author Me �rem Kavakp�nar (kavakpinarirem1@gmail.com)
* @date December,2022
* @brief : Bu s�n�f, 3B �zgara tabanl� harita olu�turmaktad�r.
*/
#include "PointCloud.h"
#include"PointCloudRecorder.h"
#include"DepthCamera.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>
class GridMap:public Map {//private uyeler tan�mland�.
private:
	int depth = 0;
	bool* map = new bool[depth * depth * depth];
	float gridSize = 0;

public:
	GridMap() {

	}
	//GridMap icin constructor.
	GridMap(int _depth) :depth(_depth) {
		for (int i = 0; i < depth; i++)
		{
			for (int j = 0; j < depth; j++)
			{
				for (int k = 0; k < depth; k++) {
					*(map + i * depth * depth + j * depth + k) = false;
				}
			}
		}
	}
	//koordinatlar� verilen map'i d�ndurur.
	bool* getMap(int i, int j, int k) const;
	//Grid Size'� dondurur.
	float getGridSize() const;
	//depthi dondurur.
	int getDepth() const;
	//mapin koordinatlar�n� atar.
	void setMap(int i, int j, int k, bool value);
	//gridsize'� atar.
	void setGridSize(float _gridSize);
	//depth'i atar.
	void setDepth(int _depth);
	//verilen noktalar dizisinin denk geldi�i k�p� true olarak degistirir.
	void insertPointCloud(PointCloud& pc);
	//verilen noktan�n denk geldigi kupu true olarak degistirir.
	void insertPoint(Point& p);
	//koordinatlar� verilen grid'i dondurur.
	bool getGrid(int x, int y, int z) const;
	//filename'i verilen dosyaya noktalar� yukler.
	bool loadMap(PointCloud );
	//filename'i verilen dosyay� saveler.
	bool saveMap(string fileName);
	~GridMap() {

	}

};