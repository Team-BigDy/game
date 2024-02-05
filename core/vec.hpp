#pragma once

class Vec {
public:
	float x, y;

	inline Vec() {
		x = y = 0.0f;
	};
	inline Vec(float _x, float _y) {
		x = _x; y = _y;
	}

	inline Vec& add(const Vec& v) {
		x += v.x; y += v.y;
		return *this;
	}
	inline Vec& sub(const Vec& v) {
		x -= v.x; y -= v.y;
		return *this;
	}
	inline Vec& mul(const Vec& v) {
		x *= v.x; y *= v.y;
		return *this;
	}
	inline Vec& div(const Vec& v) {
		x /= v.x; y /= v.y;
		return *this;
	}

	inline friend Vec& operator+(Vec v1, const Vec& v2) {
		return v1.add(v2);
	}
	inline friend Vec& operator-(Vec v1, const Vec& v2) {
		return v1.sub(v2);
	}
	inline friend Vec& operator*(Vec v1, const Vec& v2) {
		return v1.mul(v2);
	}
	inline friend Vec& operator/(Vec v1, const Vec& v2) {
		return v1.div(v2);
	}

	inline Vec& operator+=(const Vec& v) {
		return add(v);
	}
	inline Vec& operator-=(const Vec& v) {
		return sub(v);
	}
	inline Vec& operator*=(const Vec& v) {
		return mul(v);
	}
	inline Vec& operator/=(const Vec& v) {
		return div(v);
	}
};