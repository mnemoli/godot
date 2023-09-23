/**************************************************************************/
/*  image_loader_bmp.h                                                    */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef IMAGE_LOADER_IBMP_H
#define IMAGE_LOADER_IBMP_H

#include "core/io/image_loader.h"

class ImageLoaderIBMP : public ImageFormatLoader {
protected:
	static const unsigned BITMAP_SIGNATURE = 0x4d42;

	static const unsigned BITMAP_FILE_HEADER_SIZE = 14; // bmp_file_header_s
	static const unsigned BITMAP_INFO_HEADER_MIN_SIZE = 40; // bmp_info_header_s

	enum bmp_compression_s {
		BI_RGB = 0x00,
		BI_RLE8 = 0x01, // compressed
		BI_RLE4 = 0x02, // compressed
		BI_BITFIELDS = 0x03,
		BI_JPEG = 0x04,
		BI_PNG = 0x05,
		BI_ALPHABITFIELDS = 0x06,
		BI_CMYK = 0x0b,
		BI_CMYKRLE8 = 0x0c, // compressed
		BI_CMYKRLE4 = 0x0d // compressed
	};

	struct bmp_header_s {
		struct bmp_file_header_s {
			uint16_t bmp_signature = 0;
			uint32_t bmp_file_size = 0;
			uint32_t bmp_file_padding = 0;
			uint32_t bmp_file_offset = 0;
		} bmp_file_header;

		struct bmp_info_header_s {
			uint32_t bmp_header_size = 0;
			uint32_t bmp_width = 0;
			uint32_t bmp_height = 0;
			uint16_t bmp_planes = 0;
			uint16_t bmp_bit_count = 0;
			uint32_t bmp_compression = 0;
			uint32_t bmp_size_image = 0;
			uint32_t bmp_pixels_per_meter_x = 0;
			uint32_t bmp_pixels_per_meter_y = 0;
			uint32_t bmp_colors_used = 0;
			uint32_t bmp_important_colors = 0;
		} bmp_info_header;
	};

    PackedColorArray ideal_palette {
            Color::hex(0x000000),
            Color::hex(0x800000),
            Color::hex(0x008000),
            Color::hex(0x808000),
            Color::hex(0x000080),
            Color::hex(0x800080),
            Color::hex(0x008080),
            Color::hex(0xC0C0C0),
            Color::hex(0xC8C8C8),
            Color::hex(0xF8D8D8),
            Color::hex(0xE7E2DD),
            Color::hex(0xE3DED8),
            Color::hex(0xDFDAD4),
            Color::hex(0xDBD6D0),
            Color::hex(0xD7D2CC),
            Color::hex(0xD3CEC7),
            Color::hex(0xCFCAC3),
            Color::hex(0xCBC6BF),
            Color::hex(0xC7C2BB),
            Color::hex(0xC3BEB6),
            Color::hex(0x757575),
            Color::hex(0x6F6F6F),
            Color::hex(0x6A6A6A),
            Color::hex(0x656565),
            Color::hex(0x606060),
            Color::hex(0x5B5B5B),
            Color::hex(0x565656),
            Color::hex(0x515151),
            Color::hex(0x4C4C4C),
            Color::hex(0x464646),
            Color::hex(0x424242),
            Color::hex(0x3A3A3A),
            Color::hex(0x333333),
            Color::hex(0x2C2C2C),
            Color::hex(0x242424),
            Color::hex(0x1D1D1D),
            Color::hex(0x161616),
            Color::hex(0x0E0E0E),
            Color::hex(0x070707),
            Color::hex(0x000000),
            Color::hex(0xDCC296),
            Color::hex(0xD5BB90),
            Color::hex(0xCFB58A),
            Color::hex(0xC8AF85),
            Color::hex(0xC2A97F),
            Color::hex(0xBBA27A),
            Color::hex(0xB59C74),
            Color::hex(0xAE966F),
            Color::hex(0xA89069),
            Color::hex(0xA28963),
            Color::hex(0x874122),
            Color::hex(0x7F3D20),
            Color::hex(0x77391E),
            Color::hex(0x70351C),
            Color::hex(0x68311A),
            Color::hex(0x612D18),
            Color::hex(0x592916),
            Color::hex(0x522514),
            Color::hex(0x4A2112),
            Color::hex(0x421D10),
            Color::hex(0xB47316),
            Color::hex(0xAF6D13),
            Color::hex(0xAA6811),
            Color::hex(0xA5630E),
            Color::hex(0xA15E0C),
            Color::hex(0x9C5809),
            Color::hex(0x975307),
            Color::hex(0x934E04),
            Color::hex(0x8E4902),
            Color::hex(0x894400),
            Color::hex(0xF09EB7),
            Color::hex(0xE999B2),
            Color::hex(0xE395AD),
            Color::hex(0xDD91A8),
            Color::hex(0xD68DA3),
            Color::hex(0xD0889E),
            Color::hex(0xCA8499),
            Color::hex(0xC38094),
            Color::hex(0xBD7C8F),
            Color::hex(0xB7778B),
            Color::hex(0xA82901),
            Color::hex(0xA42801),
            Color::hex(0x9F2701),
            Color::hex(0x9B2601),
            Color::hex(0x972501),
            Color::hex(0x922401),
            Color::hex(0x8E2301),
            Color::hex(0x8A2201),
            Color::hex(0x852101),
            Color::hex(0x812001),
            Color::hex(0x6B4A0C),
            Color::hex(0x65440B),
            Color::hex(0x603E0B),
            Color::hex(0x5B390B),
            Color::hex(0x56330B),
            Color::hex(0x512D0A),
            Color::hex(0x4C270A),
            Color::hex(0x47220A),
            Color::hex(0x421C0A),
            Color::hex(0x3C1609),
            Color::hex(0xA68A38),
            Color::hex(0xA28537),
            Color::hex(0x9E8137),
            Color::hex(0x9A7D37),
            Color::hex(0x967836),
            Color::hex(0x937436),
            Color::hex(0x8F7036),
            Color::hex(0x8B6B35),
            Color::hex(0x876735),
            Color::hex(0x846235),
            Color::hex(0x62707D),
            Color::hex(0x5D6976),
            Color::hex(0x586370),
            Color::hex(0x535D69),
            Color::hex(0x4E5763),
            Color::hex(0x49505D),
            Color::hex(0x444A56),
            Color::hex(0x3F4450),
            Color::hex(0x3A3E4A),
            Color::hex(0x363843),
            Color::hex(0x9A8E73),
            Color::hex(0x968A70),
            Color::hex(0x93876D),
            Color::hex(0x90846B),
            Color::hex(0x8C8168),
            Color::hex(0x897E66),
            Color::hex(0x867B63),
            Color::hex(0x827861),
            Color::hex(0x7F755E),
            Color::hex(0x7C715B),
            Color::hex(0x55AB57),
            Color::hex(0x3CA147),
            Color::hex(0x159917),
            Color::hex(0x358336),
            Color::hex(0x307B1C),
            Color::hex(0x107919),
            Color::hex(0x276217),
            Color::hex(0x2F5E2B),
            Color::hex(0x135C14),
            Color::hex(0x104111),
            Color::hex(0x2B61C3),
            Color::hex(0x3846E3),
            Color::hex(0x333BFF),
            Color::hex(0x3343CE),
            Color::hex(0x161AD7),
            Color::hex(0x2E3CB6),
            Color::hex(0x161CA9),
            Color::hex(0x2A4290),
            Color::hex(0x192277),
            Color::hex(0x111953),
            Color::hex(0xD8F0FF),
            Color::hex(0xACE0FF),
            Color::hex(0x99D6FF),
            Color::hex(0x82CAFF),
            Color::hex(0x75B6E8),
            Color::hex(0x68C0FF),
            Color::hex(0x5196DC),
            Color::hex(0x189CCE),
            Color::hex(0x568BB9),
            Color::hex(0x1E89A9),
            Color::hex(0xEBEDA7),
            Color::hex(0xEAEB90),
            Color::hex(0xD1CC77),
            Color::hex(0xF7F400),
            Color::hex(0xEDE832),
            Color::hex(0xC3C40B),
            Color::hex(0xC3C334),
            Color::hex(0x9FA217),
            Color::hex(0x9F9F43),
            Color::hex(0x6E7A2E),
            Color::hex(0xFFFFFF),
            Color::hex(0xC0E4E7),
            Color::hex(0xACC6D5),
            Color::hex(0xA7A7B1),
            Color::hex(0xA0A0A8),
            Color::hex(0x74A0B6),
            Color::hex(0x8399B1),
            Color::hex(0x8399B1),
            Color::hex(0x8098B0),
            Color::hex(0x8098B0),
            Color::hex(0xE2BEAC),
            Color::hex(0xD59390),
            Color::hex(0xD7766E),
            Color::hex(0xB87367),
            Color::hex(0x9F7773),
            Color::hex(0xA26A5D),
            Color::hex(0x896458),
            Color::hex(0x98574D),
            Color::hex(0x6A4542),
            Color::hex(0x5A3C31),
            Color::hex(0x729E8C),
            Color::hex(0x008080),
            Color::hex(0x427A75),
            Color::hex(0x008080),
            Color::hex(0x397860),
            Color::hex(0x3D5A63),
            Color::hex(0x265847),
            Color::hex(0x21412B),
            Color::hex(0x123930),
            Color::hex(0xFFFFFF),
            Color::hex(0xFFFFFF),
            Color::hex(0xF4F6D8),
            Color::hex(0xE9D8C2),
            Color::hex(0x2C5F59),
            Color::hex(0xD3F4C5),
            Color::hex(0xC4D39F),
            Color::hex(0xFFC71A),
            Color::hex(0xB0B89B),
            Color::hex(0xAFB177),
            Color::hex(0xA5948E),
            Color::hex(0xACA98F),
            Color::hex(0xD7A014),
            Color::hex(0xC67F08),
            Color::hex(0xCA6E46),
            Color::hex(0x798E61),
            Color::hex(0x997E4D),
            Color::hex(0x808080),
            Color::hex(0x659B2A),
            Color::hex(0x00CB16),
            Color::hex(0xA76C39),
            Color::hex(0xFF4200),
            Color::hex(0x976442),
            Color::hex(0x99652A),
            Color::hex(0xDD346A),
            Color::hex(0x294475),
            Color::hex(0x5869B5),
            Color::hex(0x426B84),
            Color::hex(0x506480),
            Color::hex(0x75594A),
            Color::hex(0x99B4D1),
            Color::hex(0xBFCDDB),
            Color::hex(0xF0F0F0),
            Color::hex(0xFFFFFF),
            Color::hex(0x646464),
            Color::hex(0x000000),
            Color::hex(0x000000),
            Color::hex(0x000000),
            Color::hex(0xB4B4B4),
            Color::hex(0xF4F7FC),
            Color::hex(0xABABAB),
            Color::hex(0x0078D7),
            Color::hex(0xFFFFFF),
            Color::hex(0xF0F0F0),
            Color::hex(0x0078D7),
            Color::hex(0x000000),
            Color::hex(0xFFFFFF),
            Color::hex(0x6D6D6D),
            Color::hex(0x000000),
            Color::hex(0x808080),
            Color::hex(0xFF0000),
            Color::hex(0x00FF00),
            Color::hex(0xFFFF00),
            Color::hex(0x0000FF),
            Color::hex(0xFF00FF),
            Color::hex(0x00FFFF),
            Color::hex(0x000000)
    };

	static Error convert_to_image(Ref<Image> p_image,
			const uint8_t *p_buffer,
			const uint8_t *p_color_buffer,
			const uint32_t color_table_size,
			const bmp_header_s &p_header);

public:
	virtual Error load_image(Ref<Image> p_image, Ref<FileAccess> f, BitField<ImageFormatLoader::LoaderFlags> p_flags, float p_scale);
	virtual void get_recognized_extensions(List<String> *p_extensions) const;
	ImageLoaderIBMP();
};

#endif // IMAGE_LOADER_IBMP_H
