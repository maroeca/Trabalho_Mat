#pragma once

#include "ofMain.h"
#include<iostream>
#include<math.h>
#include<cmath>

class Matriz3
{
private:
	float M[3][3];

public:

	/*CONSTRUTORES*/
	Matriz3(); //Cria um matriz identidade
	Matriz3(float a, float b, float c,
			float d, float e, float f,
			float g, float h, float i); //cria uma matriz com os valores passados
	Matriz3(float a); //cria matriz com todos os elementos iguais
	Matriz3(const Matriz3& other); //Construtor de cópia

	/*OPERADORES*/
	Matriz3& operator=(const Matriz3& other); //atribuição
	Matriz3 operator*(const Matriz3& other) const; //Multiplicação

	/*OPERAÇÕES*/
	float determinante() const ; //retorna o determinante
	Matriz3 cof(); //retorna o determinante da menor
	Matriz3 inversa();
	Matriz3 transposta(); //retorna a matriz transposta
	Matriz3 adjunta(); //retorna a matriz adjunta

	ofVec2f transform(const ofVec2f& vector, float z = 1.0f) const; //transforma um vetor

	/*TRANFORMAÇÕES*/

	static Matriz3 translate(float x, float y); //translada
	static Matriz3 rotate(float angle); //rotaciona
	static Matriz3 scale(int sx, int sy); //escalona

	/*OPCIONAIS*/

	/*ACESSO AOS AOS ELEMENTOS POR ()*/
	float getElement(int i, int j); //retorna o elemento na posição i,j
	void setElement(int i, int j, float valor); //atribui um valor ao elemento da posição i,jS

	float a(); 
	float b();
	float c();
	float d();
	float e();
	float f();
	float g();
	float h();
	float k();

	/*SOMA E SUBTRAÇÃO DE MATRIZ*/
	Matriz3 operator+(const Matriz3& other)const; //soma
	Matriz3 operator+=(const Matriz3& other);
	Matriz3 operator-(const Matriz3& other)const; //subtração
	Matriz3 operator-=(const Matriz3& other);

	ofMatrix4x4 to4x4();

	~Matriz3();
};

