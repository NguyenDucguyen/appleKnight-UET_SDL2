#ifndef MATH_H_
#define MATH_H_
 class Math {
public:
	static float Clamp(float value, float min, float max) {
		if (value < min)
			return min;
		if (value > max)
			return max;
		return value;
	}
};

#endif