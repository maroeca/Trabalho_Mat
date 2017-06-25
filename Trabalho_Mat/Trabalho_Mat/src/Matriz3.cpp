#include "Matriz3.h"

#define PI 3.141592653589793846


Matriz3::Matriz3()
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			if (i == k)
				M[i][k] = 1;
			else
				M[i][k] = 0;
		}
	}
}

Matriz3::Matriz3(float a, float b, float c, float d, float e, float f, float g, float h, float i)
{
	M[0][0] = a;
	M[0][1] = b;
	M[0][2] = c;
	M[1][0] = d;
	M[1][1] = e;
	M[1][2] = f;
	M[2][0] = g;
	M[2][1] = h;
	M[2][2] = i;
}

Matriz3::Matriz3(float a)
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			M[i][k] = a;
		}
	}
}

Matriz3::Matriz3(const Matriz3 & other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			M[i][j] = other.M[i][j];
		}
	}
}

Matriz3 & Matriz3::operator=(const Matriz3 & other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			M[i][j] = other.M[i][j];
		}
	}
	return *this;
	// TODO: insert return statement here
}

Matriz3 Matriz3::operator*(const Matriz3 & other) const
{
	Matriz3 result;
	float soma;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			 soma = 0;
			for (int n = 0; n < 3; n++)
			{
				soma += M[i][n] * other.M[n][j];
			}
			result.M[i][j] = soma;
		}
	}
	return result;
}

float Matriz3::determinante() const
{
	return M[0][0] * M[1][1] * M[2][2] +
		   M[0][1] * M[1][2] * M[2][0] +
		   M[0][2] * M[1][0] * M[2][1] -
		   M[2][0] * M[1][1] * M[0][2] -
		   M[2][1] * M[1][2] * M[0][0] -
		   M[2][2] * M[1][0] * M[0][1];
}

Matriz3 Matriz3::cof()
{
	Matriz3 result = Matriz3();
	float menor[2][2]; 
	int posi = 0;
	int posj = 0; 
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{			
			for (int y = 0; y < 3; y++)
				for (int x = 0; x < 3; x++)
					if (i != y && j != x)
					{
						if (posi < 2)
						{
							menor[posj][posi] = M[y][x];
							posi++;
						}
						if (posj < 1 && posi > 1)
						{
							posi = 0;
							posj++;
						}
					}
			if ((i + j) % 2 != 0)
				result.M[i][j] = menor[0][0] * menor[1][1] - menor[0][1] * menor[1][0];
			else
				result.M[i][j] = -(menor[0][0] * menor[1][1] - menor[0][1] * menor[1][0]);
		}
	}
	return result;
}

Matriz3 Matriz3::inversa()
{
	Matriz3 result;
	if (determinante() != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				result.M[i][j] = adjunta().M[i][j] / determinante();
			}
		}
	}
	return result;
}

Matriz3 Matriz3::transposta()
{
	Matriz3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.M[i][j] = M[j][i];
		}
	}
	return result;
}

Matriz3 Matriz3::adjunta()
{
	return cof().transposta();
}


ofVec2f Matriz3::transform(const ofVec2f & vector, float z) const
{
	ofVec3f vetor = ofVec3f(vector.x, vector.y, z);
	ofVec3f result = ofVec3f(0, 0, 0);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i] += vetor[j] * M[j][i];
		}
	}

	return ofVec2f(result.x, result.y);
}




Matriz3 Matriz3::translate(float x, float y)
{

	return Matriz3(1, 0, 0,
				   0, 1, 0,
				   x, y, 1);
}

Matriz3 Matriz3::rotate(float angle)
{
	float rotAngle = (angle * PI ) / 180.0f;
	
	return Matriz3(cos(rotAngle), sin(rotAngle), 0,
				  -sin(rotAngle), cos(rotAngle), 0,
				   0, 0, 1);
}

Matriz3 Matriz3::scale(int sx, int sy)
{

	return Matriz3(sx, 0, 0,
				   0, sy, 0,
				   0, 0, 1);
}

float Matriz3::getElement(int i, int j)
{
	return M[i][j];
}

void Matriz3::setElement(int i, int j, float valor)
{
	M[i][j] = valor;
}

float Matriz3::a()
{
	return M[0][0];
}

float Matriz3::b()
{
	return M[0][1];
}

float Matriz3::c()
{
	return M[0][2];
}

float Matriz3::d()
{
	return M[1][0];
}

float Matriz3::e()
{
	return M[1][1];
}

float Matriz3::f()
{
	return M[1][2];
}

float Matriz3::g()
{
	return M[2][0];
}

float Matriz3::h()
{
	return M[2][1];
}

float Matriz3::k()
{
	return M[2][2];
}

Matriz3 Matriz3::operator+(const Matriz3 & other) const
{
	Matriz3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.M[i][j] = M[i][j] + other.M[i][j];
		}
	}
	return result;
}

Matriz3 Matriz3::operator+=(const Matriz3 & other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			M[i][j] += other.M[i][j];
		}
	}

	return *this;
}

Matriz3 Matriz3::operator-(const Matriz3 & other) const
{
	Matriz3 result;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result.M[i][j] = M[i][j] - other.M[i][j];
		}
	}
	return result;
}

Matriz3 Matriz3::operator-=(const Matriz3 & other)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			M[i][j] -= other.M[i][j];
		}
	}

	return *this;
}

ofMatrix4x4 Matriz3::to4x4()
{
	ofMatrix4x4 m4x4(
		a(), b(), 0.0f, c(),
		d(), e(), 0.0f, f(),
		0.0, 0.0f, 1.0f, 0.0f,
		g(), h(), 0.0f, k());
	return m4x4;
}

Matriz3::~Matriz3()
{
}
