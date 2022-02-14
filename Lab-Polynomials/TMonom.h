#pragma once
struct TMonom
{
	double coef;
	int degX, degY, degZ;

	bool operator==(const TMonom& other)
	{
		return coef == other.coef && degX == other.degX && degY == other.degY && degZ == other.degZ;
	}
	
	bool operator>(const TMonom& other)
	{
		if (degX > other.degX) return true;
		else if (degX == other.degX && degY > other.degY) return true;
		else if (degX == other.degX && degY == other.degY && degZ > other.degZ) return true;
		else if (degX == other.degX && degY == other.degY && degZ == other.degZ && coef > other.coef) return true;
		return false;
	}

	bool operator<(const TMonom& other)
	{
		if (degX < other.degX) return true;
		else if (degX == other.degX && degY < other.degY) return true;
		else if (degX == other.degX && degY == other.degY && degZ < other.degZ) return true;
		else if (degX == other.degX && degY == other.degY && degZ == other.degZ && coef < other.coef) return true;
		return false;
	}


};