#pragma once
#include "IX.h"
#include "IY.h"
#include "CA.h"


//��������������� ���������� GUID
extern const IID IID_IX;
extern const IID IID_IY;

static const IID IID_IX =
{ 0x32bb8320, 0xb41b, 0x11cf,
{ 0xa6, 0xbb,0x0,0x80,0xc7,0xb2,0xd6,0x82 } };
static const IID IID_IY =
{ 0x32bb8321, 0xb41b, 0x11cf,
{ 0xa6, 0xbb,0x0,0x80,0xc7,0xb2,0xd6,0x82 } };



void trace(const char*msg)
{
	std::cout << msg << std::endl;
}




