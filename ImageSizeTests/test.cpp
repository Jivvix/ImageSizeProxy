#include "pch.h"
#include "MemoryLeakDetector.h"
#include "ImageProxy.h"

TEST(ZeroTests, EmptyFilename) {
	MemoryLeakDetector leakDetector;
	ImageProxy proxy("");
	EXPECT_FALSE(proxy.extent_loaded());
	proxy.get_extent();
	EXPECT_FALSE(proxy.extent_loaded());
}

TEST(ZeroTests, ZeroSizedBitmap) {
	MemoryLeakDetector leakDetector;
	Bitmap bitmap = Bitmap();
	bitmap.save("ZeroSized.bmp");
	ImageProxy proxy("ZeroSized.bmp");
	EXPECT_FALSE(proxy.extent_loaded());
	EXPECT_EQ(proxy.get_extent(), Rect(0,0));
	EXPECT_TRUE(proxy.extent_loaded());
}

TEST(NameTests, UndefinedName) {
	MemoryLeakDetector leakDetector;

	ImageProxy proxy("Undefined.bmp");
	proxy.get_extent();
	EXPECT_FALSE(proxy.extent_loaded());
}

TEST(NameTests, UnderscoreName) {
	MemoryLeakDetector leakDetector;

	ImageProxy proxy("Undefined_.bmp");
	proxy.get_extent();
	EXPECT_FALSE(proxy.extent_loaded());
}

TEST(NameTests, OneNumberName) {
	MemoryLeakDetector leakDetector;

	ImageProxy proxy("Undefined_4455.bmp");
	proxy.get_extent();
	EXPECT_FALSE(proxy.extent_loaded());
}

TEST(NameTests, NumberAndxName) {
	MemoryLeakDetector leakDetector;

	ImageProxy proxy("Undefined_445x.bmp");
	proxy.get_extent();
	EXPECT_FALSE(proxy.extent_loaded());
}

