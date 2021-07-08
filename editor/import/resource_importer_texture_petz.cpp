#include "resource_importer_texture_petz.h"
#include "scene/resources/texture.h"
#include <core\io\image_loader.h>

ResourceImporterTexturePetz *ResourceImporterTexturePetz::singleton = NULL;

String ResourceImporterTexturePetz::get_importer_name() const {
	return "PetzTexture";
}

String ResourceImporterTexturePetz::get_visible_name() const {
	return "Petz Texture";
}

void ResourceImporterTexturePetz::get_recognized_extensions(List<String> *p_extensions) const {
	p_extensions->push_back("bmp");
}

String ResourceImporterTexturePetz::get_save_extension() const {
	return "stex";
}
 
String ResourceImporterTexturePetz::get_resource_type() const {
	return "StreamTexture";
}

void ResourceImporterTexturePetz::get_import_options(List<ImportOption> *r_options, int p_preset) const {
}

bool ResourceImporterTexturePetz::get_option_visibility(const String &p_option, const Map<StringName, Variant> &p_options) const {
	return true;
}

ResourceImporterTexturePetz::ResourceImporterTexturePetz() {
	Ref<Image> palette_image;
	palette_image.instance();
	ImageLoader::load_image("res://resources/textures/petzpalette.png", palette_image);
	palette_image->lock();
	for (int i = 0; i < palette_image->get_width(); i++) {
		palette.push_back(palette_image->get_pixel(i, 0));
	}
	palette_image->unlock();
	palette_image.unref();
	singleton = this;
}

ResourceImporterTexturePetz::~ResourceImporterTexturePetz() {
}

void ResourceImporterTexturePetz::_save_stex(const Ref<Image> &p_image, const String &p_to_path, int p_texture_flags) {
	FileAccess *f = FileAccess::open(p_to_path, FileAccess::WRITE);
	f->store_8('G');
	f->store_8('D');
	f->store_8('S');
	f->store_8('T'); //godot streamable texture

	bool resize_to_po2 = false;

	f->store_16(p_image->get_width());
	f->store_16(0);
	f->store_16(p_image->get_height());
	f->store_16(0);
	f->store_32(p_texture_flags);

	uint32_t format = 0;

	Ref<Image> image = p_image->duplicate();
	image->clear_mipmaps();

	int mmc = image->get_mipmap_count() + 1;

	format |= StreamTexture::FORMAT_BIT_LOSSLESS;
	f->store_32(format);
	f->store_32(mmc);

	for (int i = 0; i < mmc; i++) {

		if (i > 0) {
			image->shrink_x2();
		}

		PoolVector<uint8_t> data = Image::lossless_packer(image);
		int data_len = data.size();
		f->store_32(data_len);

		PoolVector<uint8_t>::Read r = data.read();
		f->store_buffer(r.ptr(), data_len);
	}

	memdelete(f);
}

Error ResourceImporterTexturePetz::import(const String &p_source_file, const String &p_save_path, const Map<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata) {
	Ref<Image> image;
	image.instance();
	Error err = ImageLoader::load_image(p_source_file, image, NULL, false, 1.0f, true, &palette, true);
	if (err != OK)
		return err;

	int tex_flags = 0;
	tex_flags |= Texture::FLAG_REPEAT;

	_save_stex(image, p_save_path + ".stex", tex_flags);
	return OK;
}
