#pragma once
struct TMonom
{
	double coef;
	int degX, degY, degZ;

	TMonom()
	{
		this->coef = 0;
		this->degX = 0;
		this->degY = 0;
		this->degZ = 0;
	}

	TMonom(double coef, int degX, int degY, int degZ)
	{
		this->coef = coef;
		this->degX = degX;
		this->degY = degY;
		this->degZ = degZ;
	}

	bool operator==(const TMonom& other)
	{
		return degX == other.degX && degY == other.degY && degZ == other.degZ;
	}
	
	bool operator>(const TMonom& other)
	{
		if (degX > other.degX) return true;
		else if (degX == other.degX && degY > other.degY) return true;
		else if (degX == other.degX && degY == other.degY && degZ > other.degZ) return true;
		return false;
	}

	bool operator<(const TMonom& other)
	{
		if (degX < other.degX) return true;
		else if (degX == other.degX && degY < other.degY) return true;
		else if (degX == other.degX && degY == other.degY && degZ < other.degZ) return true;
		return false;
	}
	bool EqualCoef(const TMonom& other)
	{
		return degX == other.degX && degY == other.degY && degZ == other.degZ && coef == other.coef;
	}

};