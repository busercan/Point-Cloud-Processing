/*
* @file Transform.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief 3D bir düzelmde farklý orjinlere sahip noktlarý noktayý tek bir orjine göe deðiþtiren sýnýf.
*/

//! Transform Sinifi
/*!
  Ýki koordinat duzleminin orijinleri arasindaki uzakligi ve rotasyon acilarini kullanarak
  donusum matrisini olusturur.
  Nokta ya da nokta bulutunu bu donusum matrisi ile bir donusum yapmasýný saglayarak
  nokta ya da nokta bulutunu geri dondurur.
*/
#pragma once
#include"PointCloud.h"
#include <Eigen/Dense>
#include<iomanip>

using namespace std;


class Transform {
private:
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;
	

public:
	//! Point sinifi icin constructor.
	Transform() {

	}
	//! acý deðerlerini geri döndürür
	double* getAngles() const;
	//! Donusum deðerlerini geri döndürür
	double* getTrans() const;
	//! Donusum matrixini geri döndürür
	double getTransMatrix() const;
	//! Acý degerlerini düzenler
	void setAngels(double, double, double);
	//! Donusum deðerlerini duzenler
	void setTrans(double, double, double);
	//! Donusum matrixini düzenler
	void setTansMatrix(double, int, int);
	//! Acý degerleriyle rotasyon matrisini olusturur
	void setRotation(Eigen::Vector3d ang);
	//! translation matrisini hesaplar
	void setTranslation(Eigen::Vector3d tr);
	//! verilen rotaston deðerleri ile transMatrixi düzenler
	void setRotation1(Eigen::Matrix3d rotation);
	//! alýnan noktanýn donusumunu saglar
	Point doTransform(Point p);
	//! alýnan nokta listesindeki her nokta için doTrasnform fonksiyonunu çaðýrýr
	list<Point> doTransform(list<Point> lp);
	//! alýnan nokta bulutunu nokta listesine dönüþtürür ve list için doTransform fonksiyonunu cagirir.
	PointCloud doTransform(PointCloud& pc);
	//! Point sinifi icin deconstructor.
	~Transform() {

	}
};