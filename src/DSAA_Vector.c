#include <Vector.h>
#include <DSAA_Vector.h>
#include <Utility.h>
#include <stdlib.h>

#define RESIZE_CONSTANT 2.0f

struct DSAA_Vector
{
	size_t typeSize;
	size_t size;
	size_t length;
	void *data;
};

#define GetInner(this) (struct DSAA_Vector *)this->_inner

void DSAA_Vector_Destroy(struct Vector *this);
void *DSAA_Vector_Access(struct Vector *this, size_t index);
size_t DSAA_Vector_GetLength(struct Vector *this);
void DSAA_Vector_Foreach(struct Vector *this, void (*action)(void *value, void *closure), void *closure);
void DSAA_Vector_Insert(struct Vector *this, size_t index, void *source);
void DSAA_Vector_Delete(struct Vector *this, size_t index);
void DSAA_Vector_Resize(struct Vector *this, size_t length);

struct Vector *DSAA_Vector(size_t length, size_t typeSize)
{
	struct DSAA_Vector *inner = malloc(sizeof(struct DSAA_Vector));
	inner->typeSize = typeSize;
	inner->size = length ? length : 1;
	inner->length = length;
	inner->data = malloc(inner->typeSize * inner->size);

	struct Vector *this = malloc(sizeof(struct Vector));
	this->Destroy = DSAA_Vector_Destroy;
	this->Access = DSAA_Vector_Access;
	this->GetLength = DSAA_Vector_GetLength;
	this->Foreach = DSAA_Vector_Foreach;
	this->Insert = DSAA_Vector_Insert;
	this->Delete = DSAA_Vector_Delete;
	this->Resize = DSAA_Vector_Resize;
	this->_inner = inner;

	return this;
}

void DSAA_Vector_Destroy(struct Vector *this)
{
	struct DSAA_Vector *inner = GetInner(this);
	free(inner->data);
	free(this->_inner);
	free(this);
}

void *DSAA_Vector_Access(struct Vector *this, size_t index)
{
	struct DSAA_Vector *inner = GetInner(this);
	return (void *)((char *)inner->data + (index * inner->typeSize));
}

size_t DSAA_Vector_GetLength(struct Vector *this)
{
	struct DSAA_Vector *inner = GetInner(this);
	return inner->length;
}

void DSAA_Vector_Foreach(struct Vector *this, void (*action)(void *value, void *closure), void *closure)
{
	struct DSAA_Vector *inner = GetInner(this);
	for (size_t i = 0; i < inner->length; i++)
	{
		action(this->Access(this, i), closure);
	}
}

void DSAA_Vector_Insert(struct Vector *this, size_t index, void *source)
{
	struct DSAA_Vector *inner = GetInner(this);
	this->Resize(this, inner->length + 1);
	for (size_t i = inner->length - 1; i > index; i--)
	{
		copy(this->Access(this, i), this->Access(this, i - 1), inner->typeSize);
	}
	copy(this->Access(this, index), source, inner->typeSize);
}

void DSAA_Vector_Delete(struct Vector *this, size_t index)
{
	struct DSAA_Vector *inner = GetInner(this);
	for (size_t i = index; i < inner->length - 1; i++)
	{
		copy(this->Access(this, i), this->Access(this, i + 1), inner->typeSize);
	}
	this->Resize(this, inner->length - 1);
}

void DSAA_Vector_Resize(struct Vector *this, size_t length)
{
	struct DSAA_Vector *inner = GetInner(this);
	if (inner->size == 0)
	{
		inner->size = 1;
	}
	if (length > inner->size)
	{
		for (; length > inner->size; inner->size = (size_t)(inner->size * RESIZE_CONSTANT + 0.5f))
			;
		inner->data = realloc(inner->data, inner->typeSize * inner->size);
	}
	else
	{
		for (; length < inner->size / RESIZE_CONSTANT; inner->size = (size_t)(inner->size / RESIZE_CONSTANT))
			;
		inner->data = realloc(inner->data, inner->typeSize * inner->size);
	}
	inner->length = length;
}