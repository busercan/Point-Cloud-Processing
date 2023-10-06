/*
* @file MapperInterface.cpp
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief Bir çok farklý sýnýfý altýnda toplayan ana sýnýftýr.
*/

#include "MapperInterface.h"
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include"Map.h"
#include <iostream>
using namespace std;
/*!
\param value1 acý degeri
\param value2 acý degeri
\param value3 acý degeri
*/
MapperInterface::MapperInterface() {

}
MapperInterface:: ~MapperInterface() {

}/*!
 \param gen dosyadan okunan nokta bulutlarýnýn ve transfor deðerlerinin tanýmlandýðý pointer
 */
void MapperInterface::addGenerator(PointCloudGenerator* gen) {
	this->generators.push_back(gen);
}
/*!
\param rec duzenlenecek noktalarýn pointerý
*/
void MapperInterface::setRecorder(PointCloudRecorder* rec) {
	this->recorder = rec;
}
/*!
\ return çalýþýp çalýþmadýðý
*/
bool MapperInterface::generate() {
	for (int i = 0; i <int(generators.size()); i++) {
		patch = generators[i]->captureFor();
		pointCloud = pointCloud + patch;
	}
	return true;
}
/*!
\ return çalýþýp çalýþmadýðý
*/
bool MapperInterface::recordPointCloud() {
	recorder->setfileName("Output");
	recorder->save(pointCloud);
	return true;
}
/*!
\ return çalýþýp çalýþmadýðý
*/
bool MapperInterface:: recordMap(string fileName) {
	map->saveMap(fileName);
	return true;
}
/*!
\ return çalýþýp çalýþmadýðý
*/
bool MapperInterface:: insertMap(Map* mp) {
	map = mp;
	map->loadMap(pointCloud);
	return true;
}