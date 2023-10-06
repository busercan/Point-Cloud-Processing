/*
* @file Transform.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief 3D bir d�zelmde farkl� orjinlere sahip noktlar� noktay� tek bir orjine g�e de�i�tiren s�n�f.
*/

//! Transform Sinifi
/*!
  �ki koordinat duzleminin orijinleri arasindaki uzakligi ve rotasyon acilarini kullanarak
  donusum matrisini olusturur.
  Nokta ya da nokta bulutunu bu donusum matrisi ile bir donusum yapmas�n� saglayarak
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
	//! ac� de�erlerini geri d�nd�r�r
	double* getAngles() const;
	//! Donusum de�erlerini geri d�nd�r�r
	double* getTrans() const;
	//! Donusum matrixini geri d�nd�r�r
	double getTransMatrix() const;
	//! Ac� degerlerini d�zenler
	void setAngels(double, double, double);
	//! Donusum de�erlerini duzenler
	void setTrans(double, double, double);
	//! Donusum matrixini d�zenler
	void setTansMatrix(double, int, int);
	//! Ac� degerleriyle rotasyon matrisini olusturur
	void setRotation(Eigen::Vector3d ang);
	//! translation matrisini hesaplar
	void setTranslation(Eigen::Vector3d tr);
	//! verilen rotaston de�erleri ile transMatrixi d�zenler
	void setRotation1(Eigen::Matrix3d rotation);
	//! al�nan noktan�n donusumunu saglar
	Point doTransform(Point p);
	//! al�nan nokta listesindeki her nokta i�in doTrasnform fonksiyonunu �a��r�r
	list<Point> doTransform(list<Point> lp);
	//! al�nan nokta bulutunu nokta listesine d�n��t�r�r ve list i�in doTransform fonksiyonunu cagirir.
	PointCloud doTransform(PointCloud& pc);
	//! Point sinifi icin deconstructor.
	~Transform() {

	}
};