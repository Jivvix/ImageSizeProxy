#ifndef ___LIB_BITMAP_H___
#define ___LIB_BITMAP_H___

#include <cstdint>
#include <string>

class Bitmap
{
public:
	uint8_t * m_buffer;
	size_t    m_width, m_height;

public:
	Bitmap(void) : m_buffer(nullptr), m_width(0), m_height(0)
	{}
	virtual ~Bitmap(void)
	{
		clear();
	}

public:
	bool load(const wchar_t * file_name);
	inline bool load(const std::wstring & file_name)
	{
		return load(file_name.c_str());
	}
	bool save(const wchar_t * file_name) const;
	inline bool save(const std::wstring & file_name) const
	{
		return save(file_name.c_str());
	}

public:
	void clear(void)
	{
		m_width = m_height = 0;
		delete [] m_buffer;
		m_buffer = nullptr;
	}

private:
	Bitmap(const Bitmap &);
	Bitmap & operator = (const Bitmap &);
};

#endif // ___LIB_BITMAP_H___
