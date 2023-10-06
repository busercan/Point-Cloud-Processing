/*
*@file PointCloudRecorder.cpp
*@Author Me Þeyma COÞTUR
*@date December 2022
*@brief Bu fonksiyon nokta bulutlarýnýn dosyaya kaydedilmesi için kullanýlmaktadýr. Save fonksiyonu çaðrýldýðýnda, fileName ile ismi verilen dosya açýlýr, parametre olarak verilen nokta bulutundaki noktalar bu dosyaya kaydedilir.
*/

#include "PointCloudRecorder.h"
#include "PointCloud.h"
#include <iomanip>

//PointCloudRecorder sýnýfinin yapici fonksiyonudur.
PointCloudRecorder::PointCloudRecorder()
{
	fileName = "";
}
PointCloudRecorder::PointCloudRecorder(string _fileName) {

	fileName = _fileName;
	file.open(fileName);
}

//PointCloudRecorder sýnýfinin yikici fonksiyonudur.
PointCloudRecorder::~PointCloudRecorder()
{

}

void PointCloudRecorder:: setfileName(string _fileName) {
	fileName = _fileName;
}
string PointCloudRecorder:: getfileName() {
	return fileName;
}
//Paremetre olarak vektor kullanýlmýstýr.
//Nokta bulutlarýnýn dosyaya kaydedilmesini saglar.
bool PointCloudRecorder::save(PointCloud& PC) {

	int size = PC.getpointNumber();
	ofstream recordFile;
	list<Point> P;
	P = PC.getPoints();
	recordFile.open(fileName + ".txt", ios::out | ios::app);
	list<Point>::iterator iter;

	if (recordFile.is_open()) {
		for (iter = P.begin(); iter != P.end(); iter++)
		{
			recordFile << iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
		}
		return true;
	}
	else {
		return false;
	}
	recordFile.close();
}
