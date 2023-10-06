/*
* @file MapperInterface.cpp
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief Bir �ok farkl� s�n�f� alt�nda toplayan ana s�n�ft�r.
*/

#include "MapperInterface.h"
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include"Map.h"
#include <iostream>
using namespace std;
/*!
\param value1 ac� degeri
\param value2 ac� degeri
\param value3 ac� degeri
*/
MapperInterface::MapperInterface() {

}
MapperInterface:: ~MapperInterface() {

}/*!
 \param gen dosyadan okunan nokta bulutlar�n�n ve transfor de�erlerinin tan�mland��� pointer
 */
void MapperInterface::addGenerator(PointCloudGenerator* gen) {
	this->generators.push_back(gen);
}
/*!
\param rec duzenlenecek noktalar�n pointer�
*/
void MapperInterface::setRecorder(PointCloudRecorder* rec) {
	this->recorder = rec;
}
/*!
\ return �al���p �al��mad���
*/
bool MapperInterface::generate() {
	for (int i = 0; i <int(generators.size()); i++) {
		patch = generators[i]->captureFor();
		pointCloud = pointCloud + patch;
	}
	return true;
}
/*!
\ return �al���p �al��mad���
*/
bool MapperInterface::recordPointCloud() {
	recorder->setfileName("Output");
	recorder->save(pointCloud);
	return true;
}
/*!
\ return �al���p �al��mad���
*/
bool MapperInterface:: recordMap(string fileName) {
	map->saveMap(fileName);
	return true;
}
/*!
\ return �al���p �al��mad���
*/
bool MapperInterface:: insertMap(Map* mp) {
	map = mp;
	map->loadMap(pointCloud);
	return true;
}