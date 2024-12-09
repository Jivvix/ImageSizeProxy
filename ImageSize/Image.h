#pragma once
#include "Graphic.h"
#include "libbitmap.h"

class Image final :
    public Graphic
{
    Bitmap bitmap;
public:

    Image(const std::string& file_name) {
        bitmap.load(file_name);
    }
    virtual Rect get_extent() const override {
        return Rect (bitmap.m_height, bitmap.m_width);
    }
};

