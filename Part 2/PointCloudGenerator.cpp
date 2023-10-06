/*
*@file PointCloudGenerator.cpp
*@Author Me Şeyma COŞTUR
*@date January 2023
*@brief DepthCamera nın pure virtuel sinifidir.Transform ile arasında obligation iliskisine sahiptir.
Transform  nesnesine sahiptir. Depth kameranın fonksiyonlariyla islemler gerceklestirir.
*/

#include "PointCloudGenerator.h"
#include <iostream>
//Bu fonksiyon sinifin yapici fonksiyonudur.
PointCloudGenerator::PointCloudGenerator() {

}
//Bu fonksiyon sinifin yikici fonksiyonudur.
PointCloudGenerator:: ~PointCloudGenerator() {

}
//Bu fonksiyon setleme islemini yapar.
//Input olarak alinan transform nesnesini transforma esitler.
void PointCloudGenerator::setTransform(Transform T) {
	transform = T;
}

// Transform matrixini dondurur.
Transform PointCloudGenerator::getTransform() {
	return transform;
}