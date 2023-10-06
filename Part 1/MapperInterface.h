/*
* @file MapperInterface.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief Bir çok farklý sýnýfý altýnda toplayan ana sýnýftýr.
*/

//! MapperInterface Sinifi
/*!
 dönüþümü saðlayan, harita oluþturan, okuma ve yazma sýnýfý 
 yapan sýnýflarý bir sýnýf altýnda toplayan ana sýnýftýr.
*/
#pragma once
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include"Map.h"
class MapperInterface{
private:
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
	Map* map;
public:
	//! Consturactor fonksiyonu 
	MapperInterface();
	//! Deconsturactor fonksiyonu 
	~MapperInterface();

	//! Okunan dusyalarý generator vektörü altýnda toplar
	void addGenerator(PointCloudGenerator*);
	//! Dosyaya yazýlacak verileri düzenler
	void setRecorder(PointCloudRecorder*);
	//! dönüþümün yapýldýðý fonksiyondur
	bool generate();
	//! oluþan nokta bulutunun dosyaya yazýldýðý fonksiyondur 
	bool recordPointCloud();
	//! oluþan haritanýn dosyaya yazýldýðý fonksiyondur 
	bool recordMap(string);
	//! Oluþan nokta bulutuyla harita oluþturan fonksiyon
	bool insertMap(Map*);
};

