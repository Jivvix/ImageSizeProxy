#pragma once
#include "Rect.h"

class Graphic {

public:
	virtual Rect get_extent() const = 0;
};