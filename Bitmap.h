#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>
#include <fstream>
//#include "Bitmap.h"
//#include "BitmapInfoHeader.h"
//#include "BitmapFileHeader.h"

using namespace std;

#pragma pack(2)

namespace caveofprogramming {

struct BitmapFileHeader {
	char header[2] { 'B', 'M' };
	int32_t fileSize;
	int32_t reserved { 0 };
	int32_t dataOffset;
};

struct BitmapInfoHeader {
	int32_t headerSize{40};
	int32_t width;
	int32_t height;
	int16_t planes{1};
	int16_t bitsPerPixel{24};
	int32_t compression{0};
	int32_t dataSize{0};
	int32_t horizontalResolution{2400};
	int32_t verticalResolution{2400};
	int32_t colors{0};
	int32_t importantColors{0};
};

class Bitmap {
private:
	int m_width{0};
	int m_height{0};
	unique_ptr<uint8_t[]> m_pPixels{nullptr};


public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	//bool write(string filename);
	virtual ~Bitmap();
};

Bitmap::Bitmap(int width, int height) :
		m_width(width), m_height(height), m_pPixels(
				new uint8_t[width * height * 3] { }) {

}

/*
bool Bitmap::write(string filename) {

	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)
			+ m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;
	file.open(filename, ios::out | ios::binary);

	if (!file) {
		return false;
	}

	file.write((char *) &fileHeader, sizeof(fileHeader));
	file.write((char *) &infoHeader, sizeof(infoHeader));
	file.write((char *) m_pPixels.get(), m_width * m_height * 3);

	file.close();

	if (!file) {
		return false;
	}

	return true;
}
*/

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t *pPixel = m_pPixels.get();

	pPixel += (y * 3) * m_width + (x * 3);

	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

Bitmap::~Bitmap() {
	// TODO Auto-generated destructor stub
}

} /* namespace caveofprogramming */

#endif /* BITMAP_H_ */
