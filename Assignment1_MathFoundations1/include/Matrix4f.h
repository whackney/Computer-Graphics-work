// High level design note
// Our matrix should match the behavior of the glm library.
#ifndef MATRIX4F_H
#define MATRIX4F_H

#include <cmath>

// We need to Vector4f header in order to multiply a matrix
// by a vector.
#include "Vector4f.h"

// Matrix 4f represents 4x4 matrices in Math
struct Matrix4f{
private:
    float n[4][4];  // Store each value of the matrix

public:
    Matrix4f() = default;

    // Matrix constructor with 9 scalar values.
    Matrix4f( float n00, float n01, float n02, float n03,
              float n10, float n11, float n12, float n13,
              float n20, float n21, float n22, float n23,
              float n30, float n31, float n32, float n33){

        n[0][0] = n00; n[0][1] = n01; n[0][2] = n02; n[0][3] = n03;
        n[1][0] = n10; n[1][1] = n11; n[1][2] = n12; n[1][3] = n13;
        n[2][0] = n20; n[2][1] = n21; n[2][2] = n22; n[2][3] = n23;
        n[3][0] = n30; n[3][1] = n31; n[3][2] = n32; n[3][3] = n33;
    }

    // Matrix constructor from four vectors.
    // Note: 'd' will almost always be 0,0,0,1
    Matrix4f(const Vector4f& a, const Vector4f& b, const Vector4f& c, const Vector4f& d){
      n[0][0] = a.x; n[0][1] = b.x; n[0][2] = c.x; n[0][3] = d.x;
      n[1][0] = a.y; n[1][1] = b.y; n[1][2] = c.y; n[1][3] = d.y;
      n[2][0] = a.z; n[2][1] = b.z; n[2][2] = c.z; n[2][3] = d.z;
      n[3][0] = a.w; n[3][1] = b.w; n[3][2] = c.w; n[3][3] = d.w;
    }

    // Makes the matrix an identity matrix
    void identity(){
		n[0][0] = 1; n[0][1] = 0; n[0][2] = 0; n[0][3] = 0;
		n[1][0] = 0; n[1][1] = 1; n[1][2] = 0; n[1][3] = 0;
		n[2][0] = 0; n[2][1] = 0; n[2][2] = 1; n[2][3] = 0;
		n[3][0] = 0; n[3][1] = 0; n[3][2] = 0; n[3][3] = 1;
    }

    // Index operator with two dimensions
    // Example: M(1,1) returns row 1 and column 1 of matrix M.
    float& operator ()(int i, int j){
      return (n[j][i]);
    }

    // Index operator with two dimensions
    // Example: M(1,1) returns row 1 and column 1 of matrix M.
    const float& operator ()(int i, int j) const{
      return (n[j][i]);
    }

    // Return a single  vector from the matrix (row or columnn major? hmm).
    Vector4f& operator [](int j){
      return (*reinterpret_cast<Vector4f *>(n[j]));
    }

    // Return a single  vector from the matrix (row or columnn major? hmm).
    const Vector4f& operator [](int j) const{
      return (*reinterpret_cast<const Vector4f *>(n[j]));
    }

    // Make a matrix rotate about various axis
    Matrix4f MakeRotationX(float t){
        Matrix4f n;
        n.identity();
        float radX = qDegreesToRadians(t);
        n[1][1] = qCos(radX);
        n[1][2] = qSin(radX);
        n[2][1] = -qSin(radX);
        n[2][2] = qCos(radX);
        return(n);
    }
    Matrix4f MakeRotationY(float t){
        Matrix4f n;
        n.identity();
        float radY = qDegreesToRadians(t);
        n[0][0] = qCos(radY);
        n[0][2] = -qSin(radY);
        n[2][0] = qSin(radY);
        n[2][2] = qCos(radY);
        return(n);
    }
    Matrix4f MakeRotationZ(float t){
        Matrix4f n;
        n.identity();
        float radZ = qDegreesToRadians(t);
        n[0][0] = qCos(radZ);
        n[0][1] = qSin(radZ);
        n[1][0] = -qSin(radZ);
        n[1][1] = qCos(radZ);
        return(n);
    }
    Matrix4f MakeScale(float sx,float sy, float sz){
        Matrix4f n;
        n.identity();
        n[0][0] = n[0][0] * sx;
        n[1][1] = n[1][1] * sy;
        n[2][2] = n[2][2] * sz;
        return(n);
    }
};

// Matrix Multiplication
Matrix4f operator *(const Matrix4f& A, const Matrix4f& B){
	Matrix4f newmatrix;
	float product;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			product = 0;
			for (int k = 0; k < 4; k++) {
				product += A[i][k] * B[k][j];
			}
			newmatrix[i][j] = product;
		}
	}
	return newmatrix;
}

// Matrix multiply by a vector
Vector4f operator *(const Matrix4f& M, const Vector4f& v){
	return Vector4f(
		M(0, 0) * v.x + M(0, 1) * v.y + M(0, 2) * v.z + M(0, 3) * v.w,
		M(1, 0) * v.x + M(1, 1) * v.y + M(1, 2) * v.z + M(1, 3) * v.w,
		M(2, 0) * v.x + M(2, 1) * v.y + M(2, 2) * v.z + M(2, 3) * v.w,
		M(3, 0) * v.x + M(3, 1) * v.y + M(3, 2) * v.z + M(3, 3) * v.w);
}

#endif
