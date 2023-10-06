/*
* @file Point.h
* @Author Me Buse Ercan (busercan@hotmail.com)
* @date December,2022
* @brief 3D bir düzelmde nokta nesnesini oluþturan sýnýf.
*/
#pragma once
#include<vector>
#include<list>

//! Point class
/*
* 3 boyutlu bir düzelmde bir nokta oluþturmamýzý saðlar ve bu noktanýn kordinat bilgilerini tutar.
	Noktanýn oluþturulmasý, iki nokta arasýndaki uzaklýk, iki noktanýn eþit olup olmadýðýnýn kontrolünü yapan
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
	//! Noktaya koordinatlarýn atamalarýný yapar.
	Point(double, double, double);
	//! Iki noktanin ayni olup olmadýðýnýn kontrolünü yapar.
	bool operator==(const Point&);
	//! Iki nokta arasindaki uzakligi hesaplar.
	const double distance(const Point&);
	//! Noktanýn x koordinatýnýn degerlerini döndürür.
	double getX() const;
	//! Noktanýn y koordinatýnýn degerlerini döndürür.
	double getY() const;
	//! Noktanýn z koordinatýnýn degerlerini döndürür.
	double getZ() const;
	//! Noktanýn x koordinatýnýn degerlerini düzenler.
	void setX(double);
	//! Noktanýn y koordinatýnýn degerlerini düzenler.
	void setY(double);
	//! Noktanýn z koordinatýnýn degerlerini düzenler.
	void setZ(double);
	//! Point sinifi icin deconstructor.
	~Point();


};

