#include "libbitmap.h"

void main(void)
{
	Bitmap bmp;
	bmp.load(std::wstring(L"src\\kitty-24.bmp"));
	bmp.m_buffer[10000] = 0x30;
	bmp.save(std::wstring(L"out.bmp"));
}
