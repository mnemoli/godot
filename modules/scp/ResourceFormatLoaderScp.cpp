
#include "ResourceFormatLoaderScp.h"
#include "PetzScpResource.h"

Ref<Resource> ResourceFormatLoaderScp::load(const String &p_path, const String &p_original_path, Error *r_error, bool p_use_sub_threads, float *r_progress, CacheMode p_cache_mode) {
	Ref<PetzScpResource> animation = memnew(PetzScpResource);
	if (r_error) {
		*r_error = OK;
	}
	*r_error = animation->load_file(p_path);
	return animation;
}

void ResourceFormatLoaderScp::get_recognized_extensions(List<String> *r_extensions) const {
	if (!r_extensions->find("scp")) {
		r_extensions->push_back("scp");
	}
}

String ResourceFormatLoaderScp::get_resource_type(const String &p_path) const {
	if(p_path.to_lower().contains("scp"))
		return "PetzScpResource";
	else
		return "";
}

bool ResourceFormatLoaderScp::handles_type(const String &p_type) const {
	return ClassDB::is_parent_class(p_type, "PetzScpResource");
}