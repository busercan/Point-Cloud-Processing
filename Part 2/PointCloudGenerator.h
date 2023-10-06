/*
*@file PointCloudGenerator.h
*@Author Me Şeyma COŞTUR
*@date January 2023
*@brief  DepthCamera nın pure virtuel sinifidir.Transform ile arasında obligation iliskisine sahiptir.
Transform  nesnesine sahiptir. Depth kameranın fonksiyonlariyla islemler gerceklestirir.
*/
#pragma once
#include "Transform.h"
//PointCloudGenerator sinifi
class PointCloudGenerator {
private:
	Transform transform;
public:
	//Bu fonksiyon sinifin yapici fonksiyonudur.
	PointCloudGenerator();
	//Bu fonksiyon sinifin yikici fonksiyonudur.
	~PointCloudGenerator();
	//Bu fonksiyon setleme islemini yapar.
	void setTransform(Transform);
	// Transformu dondurur.
	Transform getTransform();
	//Dosyadaki noktalari okur.
	virtual PointCloud capture() = 0;
	//Dosyadaki noktalari okur ve transform islemini yapar.
	virtual PointCloud captureFor() = 0;
}; 
