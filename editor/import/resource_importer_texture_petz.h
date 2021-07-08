#pragma once
#include "core/image.h"
#include "core/io/resource_importer.h"

class ResourceImporterTexturePetz : public ResourceImporter {
	GDCLASS(ResourceImporterTexturePetz, ResourceImporter);

protected:
	static ResourceImporterTexturePetz *singleton;
	PoolColorArray palette;

public:
	virtual String get_importer_name() const;
	virtual String get_visible_name() const;
	virtual void get_recognized_extensions(List<String> *p_extensions) const;
	virtual String get_save_extension() const;
	virtual String get_resource_type() const;

	virtual void get_import_options(List<ImportOption> *r_options, int p_preset = 0) const;
	virtual bool get_option_visibility(const String &p_option, const Map<StringName, Variant> &p_options) const;

	ResourceImporterTexturePetz();
	~ResourceImporterTexturePetz();

	static ResourceImporterTexturePetz *get_singleton() { return singleton; }

	void _save_stex(const Ref<Image> &p_image, const String &p_to_path, int p_texture_flags);

	virtual Error import(const String &p_source_file, const String &p_save_path, const Map<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files = NULL, Variant *r_metadata = NULL);
};
