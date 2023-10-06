/*
* @file MapperInterface.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief Bir çok farklı sınıfı altında toplayan ana sınıftır.
*/

//! MapperInterface Sinifi
/*!
 dönüşümü sağlayan, harita oluşturan, okuma ve yazma sınıfı 
 yapan sınıfları bir sınıf altında toplayan ana sınıftır.
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

	//! Okunan dusyaları generator vektörü altında toplar
	void addGenerator(PointCloudGenerator*);
	//! Dosyaya yazılacak verileri düzenler
	void setRecorder(PointCloudRecorder*);
	//! dönüşümün yapıldığı fonksiyondur
	bool generate();
	//! oluşan nokta bulutunun dosyaya yazıldığı fonksiyondur 
	bool recordPointCloud();
	//! oluşan haritanın dosyaya yazıldığı fonksiyondur 
	bool recordMap(string);
	//! Oluşan nokta bulutuyla harita oluşturan fonksiyon
	bool insertMap(Map*);
};
