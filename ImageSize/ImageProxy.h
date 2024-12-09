#pragma once
#include "Graphic.h"
#include "libbitmap.h"
#include "StrExtentParser.h"
//утечка памяти

class ImageProxy final : Graphic {
    std::string filename;
    mutable Rect extent = Rect(0, 0);
    mutable bool _extent_loaded;
    bool try_load_extent_from_header() const {
        StrExtentParser parser(filename);
        extent = parser.parse();
        _extent_loaded = parser.is_parsed();
        return parser.is_parsed();
    }
public:
    ImageProxy(const std::string& file_name) : filename(file_name), _extent_loaded(false) {};
    bool extent_loaded() const { return _extent_loaded; };
    virtual Rect get_extent() const override {
        if (_extent_loaded) {
            return extent;
        }
        if (try_load_extent_from_header()) {
            return extent;
        }
        Bitmap bitmap;
        _extent_loaded = bitmap.load(filename);
        extent = Rect(bitmap.m_height, bitmap.m_width);
        return extent;
    }
};