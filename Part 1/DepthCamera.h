/* * @file DepthCamera.h
* @Author Me Beyza Uygur(beyzauygur989@gmail.com)
* @date December,2022
*@brief capture fonksiyonu çaðrýldýðýnda noktalarý okuyan ve yaratýlan nokta bulutu
nesnesine bu noktalarý atayan sýnýf.
fileName dosyasýndan noktalarý okur nokta bulut nesnesine bu noktalarý atar.
Nokta bulutnu döndürür.Noktalar dosyadan alýnýr.*/
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
	void setFileName(const string&);//fileName yi public deðiþkenine eþitler.
	string getFileName()const;//dosyayý döndürür.
	PointCloud capture();//fileName dosyasýný okuyup pointcloud nesnesine atar.
	PointCloud captureFor();
};


