/* * @file DepthCamera.h
* @Author Me Beyza Uygur(beyzauygur989@gmail.com)
* @date December,2022
*@brief capture fonksiyonu �a�r�ld���nda noktalar� okuyan ve yarat�lan nokta bulutu
nesnesine bu noktalar� atayan s�n�f.
fileName dosyas�ndan noktalar� okur nokta bulut nesnesine bu noktalar� atar.
Nokta bulutnu d�nd�r�r.Noktalar dosyadan al�n�r.*/
#pragma once
#include "PointCloud.h"
#include "Transform.h"
#include<iostream>
#include<fstream>
#include <string>
#include "PointCloudGenerator.h"
using namespace std;

class DepthCamera:public PointCloudGenerator {
private:
	string fileName;
public:
	DepthCamera() {

	}
	~DepthCamera() {

	}
	void setFileName(const string&);//fileName yi public de�i�kenine e�itler.
	string getFileName()const;//dosyay� d�nd�r�r.
	PointCloud capture();//fileName dosyas�n� okuyup pointcloud nesnesine atar.
	PointCloud captureFor();
};


