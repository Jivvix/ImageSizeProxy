#pragma once
struct Rect final
{
private:
	size_t _height = 0;
	size_t _width = 0;
public:
	Rect(size_t height, size_t width) : _height(height), _width(width) {};
	Rect(const Rect&) = default;
	bool operator==(Rect const&) const = default;
	size_t height() const {
		return _height;
	}
	size_t width() const {
		return _width;
	}
};

