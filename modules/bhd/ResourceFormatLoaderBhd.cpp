#include "ResourceFormatLoaderBhd.h"
#include "PetzAnimationResource.h"

Ref<Resource> ResourceFormatLoaderBhd::load(const String &p_path, const String &p_original_path, Error *r_error, bool p_use_sub_threads, float *r_progress, CacheMode p_cache_mode) {
	print_line("in load");
	Ref<PetzAnimationResource> animation = memnew(PetzAnimationResource);
	if (r_error) {
		*r_error = OK;
	}
	*r_error = animation->load_file(p_path);
	return animation;
}

void ResourceFormatLoaderBhd::get_recognized_extensions(List<String> *r_extensions) const {
	if (!r_extensions->find("bhd")) {
		r_extensions->push_back("bhd");
	}
}

String ResourceFormatLoaderBhd::get_resource_type(const String &p_path) const {
	if(p_path.to_lower().contains("bhd"))
		return "PetzAnimationResource";
	else
		return "";
}

bool ResourceFormatLoaderBhd::handles_type(const String &p_type) const {
	return ClassDB::is_parent_class(p_type, "PetzAnimationResource");
}