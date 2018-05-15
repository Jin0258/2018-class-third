#pragma once
#include "stdafx.h"
#include"Vector.h"

struct Transform2D
{
public:
	Transform2D() {}
	Transform2D(Vector2 InLocation, float InRotaion, float InScale) : Location(InLocation), Rotation(InRotaion), Scale(InScale) {};

	Matrix3 GetTRSMatrix()
	{
		Matrix3 TMat, RMat, SMat;
		TMat.SetTranslation(Location.X, Location.Y);
		RMat.SetRotation(Rotation);
		SMat.SetScale(Scale);
		return TMat * RMat * SMat;
	}

	Matrix3 GetViewMatirx()
	{
		Matrix3 TMat, RMat;
		TMat.SetTranslation(-Location.X, -Location.Y);
		RMat.SetRotation(Rotation);
		RMat.Tranpose();

		return RMat * TMat;
	}

	Vector2 Location;
	float Rotation;
	float Scale;
};