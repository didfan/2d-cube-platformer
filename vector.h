#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED 

typedef struct
{
	float x, y;
} Vector;

void SetVector(Vector* point, float x, float y);

#endif