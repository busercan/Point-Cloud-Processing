/*
* @file MapperInterface.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief Bir �ok farkl� s�n�f� alt�nda toplayan ana s�n�ft�r.
*/

//! MapperInterface Sinifi
/*!
 d�n���m� sa�layan, harita olu�turan, okuma ve yazma s�n�f� 
 yapan s�n�flar� bir s�n�f alt�nda toplayan ana s�n�ft�r.
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

	//! Okunan dusyalar� generator vekt�r� alt�nda toplar
	void addGenerator(PointCloudGenerator*);
	//! Dosyaya yaz�lacak verileri d�zenler
	void setRecorder(PointCloudRecorder*);
	//! d�n���m�n yap�ld��� fonksiyondur
	bool generate();
	//! olu�an nokta bulutunun dosyaya yaz�ld��� fonksiyondur 
	bool recordPointCloud();
	//! olu�an haritan�n dosyaya yaz�ld��� fonksiyondur 
	bool recordMap(string);
	//! Olu�an nokta bulutuyla harita olu�turan fonksiyon
	bool insertMap(Map*);
};

