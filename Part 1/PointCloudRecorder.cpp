/*
*@file PointCloudRecorder.cpp
*@Author Me �eyma CO�TUR
*@date December 2022
*@brief Bu fonksiyon nokta bulutlar�n�n dosyaya kaydedilmesi i�in kullan�lmaktad�r. Save fonksiyonu �a�r�ld���nda, fileName ile ismi verilen dosya a��l�r, parametre olarak verilen nokta bulutundaki noktalar bu dosyaya kaydedilir.
*/

#include "PointCloudRecorder.h"
#include "PointCloud.h"
#include <iomanip>

//PointCloudRecorder s�n�finin yapici fonksiyonudur.
PointCloudRecorder::PointCloudRecorder()
{
	fileName = "";
}
PointCloudRecorder::PointCloudRecorder(string _fileName) {

	fileName = _fileName;
	file.open(fileName);
}

//PointCloudRecorder s�n�finin yikici fonksiyonudur.
PointCloudRecorder::~PointCloudRecorder()
{

}

void PointCloudRecorder:: setfileName(string _fileName) {
	fileName = _fileName;
}
string PointCloudRecorder:: getfileName() {
	return fileName;
}
//Paremetre olarak vektor kullan�lm�st�r.
//Nokta bulutlar�n�n dosyaya kaydedilmesini saglar.
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
