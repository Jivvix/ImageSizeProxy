#ifndef ___LIB_BITMAP_H___
#define ___LIB_BITMAP_H___

#include <string>

// type redefinitions

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long  uint32_t;
typedef signed char  int8_t;
typedef signed short int16_t;
typedef signed long  int32_t;


class Bitmap
{
public:
	uint8_t * m_buffer;
	size_t    m_width, m_height;

public:
	Bitmap(void) : m_buffer(0), m_width(0), m_height(0) {}
	virtual ~Bitmap(void) { clear(); }

public:
	bool load(const std::wstring & file_name);
	bool save(const std::wstring & file_name) const;

public:
	void clear(void)
	{
		m_width = m_height = 0;
		delete [] m_buffer;
		m_buffer = NULL;
	}

private:
	Bitmap(const Bitmap &);
	Bitmap & operator = (const Bitmap &);
};

#endif // ___LIB_BITMAP_H___
