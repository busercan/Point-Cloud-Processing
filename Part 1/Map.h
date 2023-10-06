#pragma once
#include "PointCloud.h"
#include <string>
class Map{
public:
	Map();
	~Map();
	virtual void insertPointCloud(PointCloud& pc)=0;
	virtual void insertPoint(Point& p)=0;
	virtual bool loadMap(PointCloud)=0;
	virtual bool saveMap(string fileName)=0;

};

