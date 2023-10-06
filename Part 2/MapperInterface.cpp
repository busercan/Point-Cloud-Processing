/*
* @file MapperInterface.cpp
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief Bir çok farklı sınıfı altında toplayan ana sınıftır.
*/

#include "MapperInterface.h"
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include"Map.h"
#include <iostream>
using namespace std;
/*!
\param value1 acı degeri
\param value2 acı degeri
\param value3 acı degeri
*/
MapperInterface::MapperInterface() {

}
MapperInterface:: ~MapperInterface() {

}/*!
 \param gen dosyadan okunan nokta bulutlarının ve transfor değerlerinin tanımlandığı pointer
 */
void MapperInterface::addGenerator(PointCloudGenerator* gen) {
	this->generators.push_back(gen);
}
/*!
\param rec duzenlenecek noktaların pointerı
*/
void MapperInterface::setRecorder(PointCloudRecorder* rec) {
	this->recorder = rec;
}
/*!
\ return çalışıp çalışmadığı
*/
bool MapperInterface::generate() {
	for (int i = 0; i <int(generators.size()); i++) {
		patch = generators[i]->captureFor();
		pointCloud = pointCloud + patch;
	}
	return true;
}
/*!
\ return çalışıp çalışmadığı
*/
bool MapperInterface::recordPointCloud() {
	recorder->setfileName("Output");
	recorder->save(pointCloud);
	return true;
}
/*!
\ return çalışıp çalışmadığı
*/
bool MapperInterface:: recordMap(string fileName) {
	map->saveMap(fileName);
	return true;
}
/*!
\ return çalışıp çalışmadığı
*/
bool MapperInterface:: insertMap(Map* mp) {
	map = mp;
	map->loadMap(pointCloud);
	return true;
}