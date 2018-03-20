// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   QuickMaths.class.hpp                               :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/03/18 02:08:40 by rmc-coma          #+#    #+#             //
//   Updated: 2018/03/20 02:59:01 by rmc-coma         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef QUICKMATHS_CLASS_HPP
# define QUICKMATHS_CLASS_HPP

# include <stdint.h>
# include <unistd.h>
# include <iostream>
# include <math.h>

# define RADIANS(DEGREES)	((DEGREES) * 0.0174533)
# define DEGREES(RADIANS)	((RADIANS) / 0.0174533)

namespace qm {

	//VEC2

	template<typename T>
	class	vec2 {
	public:
		vec2(void) : x(data[0]),
					 y(data[1]) {
			this->x = static_cast<T>(0);
			this->y = static_cast<T>(0);
			return ;
		}
		vec2(const vec2<T> &that) : vec2() {
			*this = that;
			return ;
		}
		vec2(const T value) : vec2() {
			this->x = value;
			this->y = value;
			return ;
		}
		vec2(const T values[2]) : vec2() {
			this->x = values[0];
			this->y = values[1];
			return ;
		}
		vec2(const T x, const T y) : vec2() {
			this->x = x;
			this->y = y;
			return ;
		}
		virtual ~vec2(void) {
			return ;
		}

		vec2<T>		&operator=(const vec2<T> &that) {
			this->x = that.x;
			this->y = that.y;
			return (*this);
		}

		double		magnitude(void) const {
			return (static_cast<double>(sqrt(static_cast<double>(this->x) * static_cast<double>(this->x) +
											 static_cast<double>(this->y) * static_cast<double>(this->y))));
		}

		vec2<T>		&normalize(void) {
			double	mag = this->magnitude();

			this->x = static_cast<double>(this->x) / mag;
			this->y = static_cast<double>(this->y) / mag;
			return (*this);
		}

		T	&x;
		T	&y;

	private:
		friend vec2<T>		operator+(const vec2<T> &lhs, const vec2<T> &rhs) {
			return (vec2<T>(lhs.x + rhs.x, lhs.y + rhs.y));
		}
		friend vec2<T>		operator-(const vec2<T> &lhs, const vec2<T> &rhs) {
			return (vec2<T>(lhs.x - rhs.x, lhs.y - rhs.y));
		}
		friend vec2<T>		operator*(const vec2<T> &lhs, const vec2<T> &rhs) {
			return (vec2<T>(lhs.x * rhs.x, lhs.y * rhs.y));
		}
		friend vec2<T>		operator/(const vec2<T> &lhs, const vec2<T> &rhs) {
			return (vec2<T>(lhs.x / rhs.x, lhs.y / rhs.y));
		}
		friend std::ostream	&operator<<(std::ostream &out, const vec2<T> &v) {
			out << "vec2 : " << v.x << " " << v.y << std::endl;
			return (out);
		}
		friend double		dot(const vec2<T> &lhs, const vec2<T> &rhs) {
			return (static_cast<double>(lhs.x) * static_cast<double>(rhs.x) +
					static_cast<double>(lhs.y) * static_cast<double>(rhs.y));
		}
		friend vec2<T>		normalized(const vec2<T> &vector) {
			vec2<T>	v;
			
			v = vector;
			return (v.normalize());
		}
		friend double		cos(const vec2<T> &lhs, const vec2<T> &rhs) {
			return (dot(lhs, rhs) / (lhs.magnitude() * rhs.magnitude()));
		}

		friend double		angle(const vec2<T> &lhs, const vec2<T> &rhs) {
			return (acos(cos(lhs, rhs)));
		}

		T	data[2];

	};

	//VEC3

	template<typename T>
	class	vec3 {
	public:
		vec3(void) : x(data[0]),
					 y(data[1]),
					 z(data[2]) {
			this->x = static_cast<T>(0);
			this->y = static_cast<T>(0);
			this->z = static_cast<T>(0);
			return ;
		}
		vec3(const vec3<T> &that) : vec3() {
			*this = that;
			return ;
		}
		vec3(const T value) : vec3() {
			this->x = value;
			this->y = value;
			this->z = value;
			return ;
		}
		vec3(const vec2<T> &v2, const T value) : vec3() {
			this->x = v2.x;
			this->y = v2.y;
			this->z = value;
			return ;
		}
		vec3(const T values[3]) : vec3() {
			this->x = values[0];
			this->y = values[1];
			this->z = values[2];
			return ;
		}
		vec3(const T x, const T y, const T z) : vec3() {
			this->x = x;
			this->y = y;
			this->z = z;
			return ;
		}
		virtual ~vec3(void) {
			return ;
		}

		vec3<T>				&operator=(const vec3<T> &that) {
			this->x = that.x;
			this->y = that.y;
			this->z = that.z;
			return (*this);
		}

		double		magnitude(void) const {
			return (static_cast<double>(sqrt(static_cast<double>(this->x) * static_cast<double>(this->x) +
											 static_cast<double>(this->y) * static_cast<double>(this->y) +
											 static_cast<double>(this->z) * static_cast<double>(this->z))));
		}

		vec3<T>		&normalize(void) {
			double	mag = this->magnitude();

			this->x = static_cast<double>(this->x) / mag;
			this->y = static_cast<double>(this->y) / mag;
			this->z = static_cast<double>(this->z) / mag;
			return (*this);
		}

		T	&x;
		T	&y;
		T	&z;

	private:
		friend vec3<T>		operator+(const vec3<T> &lhs, const vec3<T> &rhs) {
			return (vec3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z));
		}
		friend vec3<T>		operator-(const vec3<T> &lhs, const vec3<T> &rhs) {
			return (vec3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z));
		}
		friend vec3<T>		operator*(const vec3<T> &lhs, const vec3<T> &rhs) {
			return (vec3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z));
		}
		friend vec3<T>		operator/(const vec3<T> &lhs, const vec3<T> &rhs) {
			return (vec3<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z));
		}
		friend std::ostream	&operator<<(std::ostream &out, const vec3<T> &v) {
			out << "vec3 : " << v.x << " " << v.y << " " << v.z << std::endl;
			return (out);
		}
		friend double		dot(const vec3<T> &lhs, const vec3<T> &rhs) {
			return (static_cast<double>(lhs.x) * static_cast<double>(rhs.x) +
					static_cast<double>(lhs.y) * static_cast<double>(rhs.y) +
					static_cast<double>(lhs.z) * static_cast<double>(rhs.z));
		}
		friend vec3<T>		normalized(const vec3<T> &vector) {
			vec3<T>	v;
			
			v = vector;
			return (v.normalize());
		}
		friend vec3<T>		cross(const vec3<T> &lhs, const vec3<T> &rhs) {
			vec3<T>		res;

			res.x = lhs.y * rhs.z - lhs.z * rhs.y;
			res.y = lhs.z * rhs.x - lhs.x * rhs.z;
			res.z = lhs.x * rhs.y - lhs.y * rhs.x;
			return (res);
		}
		friend double		cos(const vec3<T> &lhs, const vec3<T> &rhs) {
			return (dot(lhs, rhs) / (lhs.magnitude() * rhs.magnitude()));
		}

		friend double		angle(const vec3<T> &lhs, const vec3<T> &rhs) {
			return (acos(cos(lhs, rhs)));
		}

		T	data[3];

	};

	//VEC4

	template<typename T>
	class	vec4 {
	public:
		vec4(void) : x(data[0]),
					 y(data[1]),
					 z(data[2]),
					 w(data[3]) {
			return ;
		}
		vec4(const vec4<T> &that) : vec4() {
			*this = that;
			return ;
		}
		vec4(const T value) : vec4() {
			this->x = value;
			this->y = value;
			this->z = value;
			this->w = value;
			return ;
		}
		vec4(const vec3<T> &v3, const T value) : vec4() {
			this->x = v3.x;
			this->y = v3.y;
			this->z = v3.z;
			this->w = value;
			return ;
		}
		vec4(const T values[4]) : vec4() {
			this->x = values[0];
			this->y = values[1];
			this->z = values[2];
			this->w = values[3];
			return ;
		}
		vec4(const T x, const T y, const T z, const T w) : vec4() {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
			return ;
		}
		virtual ~vec4(void) {
			return ;
		}

		vec4<T>				&operator=(const vec4<T> &that) {
			this->x = that.x;
			this->y = that.y;
			this->z = that.z;
			this->w = that.w;
			return (*this);
		}

		double				magnitude(void) const {
			return (static_cast<double>(sqrt(static_cast<double>(this->x) * static_cast<double>(this->x) +
											 static_cast<double>(this->y) * static_cast<double>(this->y) +
											 static_cast<double>(this->z) * static_cast<double>(this->z) +
											 static_cast<double>(this->w) * static_cast<double>(this->w))));
		}

		vec4<T>				&normalize(void) {
			double	mag = this->magnitude();

			this->x = static_cast<double>(this->x) / mag;
			this->y = static_cast<double>(this->y) / mag;
			this->z = static_cast<double>(this->z) / mag;
			this->w = static_cast<double>(this->w) / mag;
			return (*this);
		}

		T	&x;
		T	&y;
		T	&z;
		T	&w;

	private:
		friend vec4<T>		operator+(const vec4<T> &lhs, const vec4<T> &rhs) {
			return (vec4<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w));
		}
		friend vec4<T>		operator-(const vec4<T> &lhs, const vec4<T> &rhs) {
			return (vec4<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w));
		}
		friend vec4<T>		operator*(const vec4<T> &lhs, const vec4<T> &rhs) {
			return (vec4<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w));
		}
		friend vec4<T>		operator/(const vec4<T> &lhs, const vec4<T> &rhs) {
			return (vec4<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w));
		}
		friend std::ostream	&operator<<(std::ostream &out, const vec4<T> &v) {
			out << "vec4 : " << v.x << " " << v.y << " " << v.z << " " << v.w << std::endl;
			return (out);
		}
		friend double		dot(const vec4<T> &lhs, const vec4<T> &rhs) {
			return (static_cast<double>(lhs.x) * static_cast<double>(rhs.x) +
					static_cast<double>(lhs.y) * static_cast<double>(rhs.y) +
					static_cast<double>(lhs.z) * static_cast<double>(rhs.z) +
					static_cast<double>(lhs.w) * static_cast<double>(rhs.w));
		}
		friend vec4<T>		normalized(const vec4<T> &vector) {
			vec4<T>	v;
			
			v = vector;
			return (v.normalize());
		}
		friend double		cos(const vec4<T> &lhs, const vec4<T> &rhs) {
			return (dot(lhs, rhs) / (lhs.magnitude() * rhs.magnitude()));
		}

		friend double		angle(const vec4<T> &lhs, const vec4<T> &rhs) {
			return (acos(cos(lhs, rhs)));
		}

		T	data[4];

	};

	//MAT4

	template<typename T>
	class	mat4 {
	public:
		mat4(void) : a(data[0]),
					 b(data[1]),
					 c(data[2]),
					 d(data[3]) {
			return ;
		}
		mat4(const mat4<T> &that) : mat4() {
			*this = that;
			return ;
		}
		mat4(const vec4<T> &a, const vec4<T> &b, const vec4<T> &c, const vec4<T> &d) : mat4() {
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
			return ;
		}
		virtual ~mat4(void) {
			return ;
		}

		mat4<T>				&operator=(const mat4<T> &that) {
			this->a = that.a;
			this->b = that.b;
			this->c = that.c;
			this->d = that.d;
			return (*this);
		}

		static mat4<T>		identity(void) {
			return (mat4<T>(vec4<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0)),
							vec4<T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0)),
							vec4<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0)),
							vec4<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1))));
		}

		mat4<T>				&lookAt(const vec3<T> &eye, const vec3<T> &center, const vec3<T> &up) {
			vec3<T>	f;
			vec3<T>	u;
			vec3<T>	s;

			f = normalized(center - eye);
			u = normalized(up);
			s = normalized(cross(f, u));
			u = cross(s, f);
			*this = mat4<T>::identity();
			this->a.x = s.x;
			this->b.x = s.y;
			this->c.x = s.z;
			this->a.y = u.x;
			this->b.y = u.y;
			this->c.y = u.z;
			this->a.z = -(f.x);
			this->b.z = -(f.y);
			this->c.z = -(f.z);
			this->d.x = -(dot(s, eye));
			this->d.y = -(dot(u, eye));
			this->d.z = dot(f, eye);
			return (*this);
		}

		mat4<T>				&projection(const double angle, const double ratio, const double near, const double far) {
			*this = mat4<T>::identity();
			this->a.x = static_cast<T>(1.0 / (ratio * tan(RADIANS(angle) / 2.0)));
			this->b.y = static_cast<T>(1.0 / (tan(RADIANS(angle) / 2.0)));
			this->c.z = static_cast<T>(-(-near - far) / (near - far));
			this->d.w = static_cast<T>(-1.0);
			return (*this);
		}

		vec4<T>		&a;
		vec4<T>		&b;
		vec4<T>		&c;
		vec4<T>		&d;

	private:
		friend std::ostream	&operator<<(std::ostream &out, const mat4<T> &mat) {
			out << "mat4 :" << std::endl;
			out << "  " << mat.a.x << "  " << mat.a.y << "  " << mat.a.z << "  " << mat.a.w << std::endl;
			out << "  " << mat.b.x << "  " << mat.b.y << "  " << mat.b.z << "  " << mat.b.w << std::endl;
			out << "  " << mat.c.x << "  " << mat.c.y << "  " << mat.c.z << "  " << mat.c.w << std::endl;
			out << "  " << mat.d.x << "  " << mat.d.y << "  " << mat.d.z << "  " << mat.d.w << std::endl;
			out << std::endl;
			return (out);
		}
		friend mat4<T>		operator+(const mat4<T> &lhs, const mat4<T> &rhs) {
			return (mat4(lhs.a + rhs.a, lhs.b + rhs.b, lhs.c + rhs.c, lhs.d + rhs.d));
		}
		friend mat4<T>		operator-(const mat4<T> &lhs, const mat4<T> &rhs) {
			return (mat4(lhs.a - rhs.a, lhs.b - rhs.b, lhs.c - rhs.c, lhs.d - rhs.d));
		}
		friend mat4<T>		operator*(const mat4<T> &lhs, const mat4<T> &rhs) {
			mat4<T>    m;

			m.a.x = lhs.a.x * rhs.a.x + lhs.b.x * rhs.a.y + lhs.c.x * rhs.a.z + lhs.d.x * rhs.a.w;
			m.b.x = lhs.a.x * rhs.b.x + lhs.b.x * rhs.b.y + lhs.c.x * rhs.b.z + lhs.d.x * rhs.b.w;
			m.c.x = lhs.a.x * rhs.c.x + lhs.b.x * rhs.c.y + lhs.c.x * rhs.c.z + lhs.d.x * rhs.c.w;
			m.d.x = lhs.a.x * rhs.d.x + lhs.b.x * rhs.d.y + lhs.c.x * rhs.d.z + lhs.d.x * rhs.d.w;
			m.a.y = lhs.a.y * rhs.a.x + lhs.b.y * rhs.a.y + lhs.c.y * rhs.a.z + lhs.d.y * rhs.a.w;
			m.b.y = lhs.a.y * rhs.b.x + lhs.b.y * rhs.b.y + lhs.c.y * rhs.b.z + lhs.d.y * rhs.b.w;
			m.c.y = lhs.a.y * rhs.c.x + lhs.b.y * rhs.c.y + lhs.c.y * rhs.c.z + lhs.d.y * rhs.c.w;
			m.d.y = lhs.a.y * rhs.d.x + lhs.b.y * rhs.d.y + lhs.c.y * rhs.d.z + lhs.d.y * rhs.d.w;
			m.a.z = lhs.a.z * rhs.a.x + lhs.b.z * rhs.a.y + lhs.c.z * rhs.a.z + lhs.d.z * rhs.a.w;
			m.b.z = lhs.a.z * rhs.b.x + lhs.b.z * rhs.b.y + lhs.c.z * rhs.b.z + lhs.d.z * rhs.b.w;
			m.c.z = lhs.a.z * rhs.c.x + lhs.b.z * rhs.c.y + lhs.c.z * rhs.c.z + lhs.d.z * rhs.c.w;
			m.d.z = lhs.a.z * rhs.d.x + lhs.b.z * rhs.d.y + lhs.c.z * rhs.d.z + lhs.d.z * rhs.d.w;
			m.a.w = lhs.a.w * rhs.a.x + lhs.b.w * rhs.a.y + lhs.c.w * rhs.a.z + lhs.d.w * rhs.a.w;
			m.b.w = lhs.a.w * rhs.b.x + lhs.b.w * rhs.b.y + lhs.c.w * rhs.b.z + lhs.d.w * rhs.b.w;
			m.c.w = lhs.a.w * rhs.c.x + lhs.b.w * rhs.c.y + lhs.c.w * rhs.c.z + lhs.d.w * rhs.c.w;
			m.d.w = lhs.a.w * rhs.d.x + lhs.b.w * rhs.d.y + lhs.c.w * rhs.d.z + lhs.d.w * rhs.d.w;
			return (m);
		}
		friend mat4<T>		operator/(const mat4<T> &lhs, const mat4<T> &rhs) {
			mat4<T>    m;

			m.a.x = lhs.a.x / rhs.a.x + lhs.b.x / rhs.a.y + lhs.c.x / rhs.a.z + lhs.d.x / rhs.a.w;
			m.b.x = lhs.a.x / rhs.b.x + lhs.b.x / rhs.b.y + lhs.c.x / rhs.b.z + lhs.d.x / rhs.b.w;
			m.c.x = lhs.a.x / rhs.c.x + lhs.b.x / rhs.c.y + lhs.c.x / rhs.c.z + lhs.d.x / rhs.c.w;
			m.d.x = lhs.a.x / rhs.d.x + lhs.b.x / rhs.d.y + lhs.c.x / rhs.d.z + lhs.d.x / rhs.d.w;
			m.a.y = lhs.a.y / rhs.a.x + lhs.b.y / rhs.a.y + lhs.c.y / rhs.a.z + lhs.d.y / rhs.a.w;
			m.b.y = lhs.a.y / rhs.b.x + lhs.b.y / rhs.b.y + lhs.c.y / rhs.b.z + lhs.d.y / rhs.b.w;
			m.c.y = lhs.a.y / rhs.c.x + lhs.b.y / rhs.c.y + lhs.c.y / rhs.c.z + lhs.d.y / rhs.c.w;
			m.d.y = lhs.a.y / rhs.d.x + lhs.b.y / rhs.d.y + lhs.c.y / rhs.d.z + lhs.d.y / rhs.d.w;
			m.a.z = lhs.a.z / rhs.a.x + lhs.b.z / rhs.a.y + lhs.c.z / rhs.a.z + lhs.d.z / rhs.a.w;
			m.b.z = lhs.a.z / rhs.b.x + lhs.b.z / rhs.b.y + lhs.c.z / rhs.b.z + lhs.d.z / rhs.b.w;
			m.c.z = lhs.a.z / rhs.c.x + lhs.b.z / rhs.c.y + lhs.c.z / rhs.c.z + lhs.d.z / rhs.c.w;
			m.d.z = lhs.a.z / rhs.d.x + lhs.b.z / rhs.d.y + lhs.c.z / rhs.d.z + lhs.d.z / rhs.d.w;
			m.a.w = lhs.a.w / rhs.a.x + lhs.b.w / rhs.a.y + lhs.c.w / rhs.a.z + lhs.d.w / rhs.a.w;
			m.b.w = lhs.a.w / rhs.b.x + lhs.b.w / rhs.b.y + lhs.c.w / rhs.b.z + lhs.d.w / rhs.b.w;
			m.c.w = lhs.a.w / rhs.c.x + lhs.b.w / rhs.c.y + lhs.c.w / rhs.c.z + lhs.d.w / rhs.c.w;
			m.d.w = lhs.a.w / rhs.d.x + lhs.b.w / rhs.d.y + lhs.c.w / rhs.d.z + lhs.d.w / rhs.d.w;
			return (m);
		}

		vec4<T>		data[4];
	};
}

#endif
