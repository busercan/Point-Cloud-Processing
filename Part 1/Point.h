/*
* @file Point.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief 3D bir d�zelmde nokta nesnesini olu�turan s�n�f.
*/
#pragma once
#include<vector>
#include<list>

//! Point class
/*
* 3 boyutlu bir d�zelmde bir nokta olu�turmam�z� sa�lar ve bu noktan�n kordinat bilgilerini tutar.
	Noktan�n olu�turulmas�, iki nokta aras�ndaki uzakl�k, iki noktan�n e�it olup olmad���n�n kontrol�n� yapan
	fonksiyonlara sahiptir.
*/
class Point {
private:
	double x;
	double y;
	double z;
public:
	//! Point sinifi icin constructor.
	Point();
	//! Noktaya koordinatlar�n atamalar�n� yapar.
	Point(double, double, double);
	//! Iki noktanin ayni olup olmad���n�n kontrol�n� yapar.
	bool operator==(const Point&);
	//! Iki nokta arasindaki uzakligi hesaplar.
	const double distance(const Point&);
	//! Noktan�n x koordinat�n�n degerlerini d�nd�r�r.
	double getX() const;
	//! Noktan�n y koordinat�n�n degerlerini d�nd�r�r.
	double getY() const;
	//! Noktan�n z koordinat�n�n degerlerini d�nd�r�r.
	double getZ() const;
	//! Noktan�n x koordinat�n�n degerlerini d�zenler.
	void setX(double);
	//! Noktan�n y koordinat�n�n degerlerini d�zenler.
	void setY(double);
	//! Noktan�n z koordinat�n�n degerlerini d�zenler.
	void setZ(double);
	//! Point sinifi icin deconstructor.
	~Point();


};

