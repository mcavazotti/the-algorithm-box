#include <stdexcept>
export module matrix2;

import vector2;

export class Matrix2 {
public:
	Matrix2(): data({0}) {}
	Matrix2(double m00, double m01, double m10, double m11) {
		data[0] = m00;
		data[1] = m01;
		data[2] = m10;
		data[3] = m11;
	}
	Matrix2(double d[]) {
		data[0] = d[0];
		data[1] = d[1];
		data[2] = d[2];
		data[3] = d[3];
	}

	double& operator()(int y, int x) {
		if (y < 0 || y > 1 || x < 0 || x > 1)
			throw std::out_of_range("Indices should be between 0 and 1");
		return data[y * 2 + x];
	}
	const double& operator()(int y, int x) const {
		if (y < 0 || y > 1 || x < 0 || x > 1)
			throw std::out_of_range("Indices should be between 0 and 1");
		return data[y * 2 + x];
	}

	Matrix2 operator+(const Matrix2& other) const { return {data[0] + other.data[0], data[1] + other.data[1], data[2] + other.data[2], data[3] + other.data[3] }; }
	Matrix2 operator-(const Matrix2& other) const { return {data[0] - other.data[0], data[1] - other.data[1], data[2] - other.data[2], data[3] - other.data[3] }; }
	Matrix2 operator*(const Matrix2& other) const { 
		return {data[0]*other.data[0] + data[1]*other.data[2], data[0]*other.data[1] + data[1]*other.data[3],
				data[2]*other.data[0] + data[3]*other.data[2], data[2]*other.data[1] + data[3]*other.data[3] };
	}
	
	Vector2 operator*(const Vector2& other) const { 
		return {data[0]*other.x + data[1]*other.y, data[2]*other.x + data[3]*other.y };
	}


	bool operator==(const Matrix2& other) const { return data[0] == other.data[0] && data[1] == other.data[1] && data[2] == other.data[2] && data[3] == other.data[3]; }
	bool operator!=(const Matrix2& other) const { return !(*this == other); }

	double det() const { return data[0] * data[3] - data[1] * data[2]; }

	Matrix2 t() const { return { data[0], data[2], data[1], data[3] }; }


private:
	double data[4];
};