/* register_types.cpp */

#include "register_types.h"

#include "PetzAnimationResource.h"
#include "ResourceFormatLoaderBhd.h"

static Ref<ResourceFormatLoaderBhd> bhd_loader;

void initialize_bhd_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	print_line("Initialising bhd");
	ClassDB::register_class<PetzAnimationResource>();
	print_line("Instantiating bhd_loader");
	bhd_loader.instantiate();
	print_line("Adding resource format loader");
	ResourceLoader::add_resource_format_loader(bhd_loader);
	print_line("Done");
}

void uninitialize_bhd_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ResourceLoader::remove_resource_format_loader(bhd_loader);
	bhd_loader.unref();
}