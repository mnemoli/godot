/* register_types.cpp */

#include "register_types.h"
#include "PetzScpResource.h"
#include "ResourceFormatLoaderScp.h"

static Ref<ResourceFormatLoaderScp> scp_loader;

void initialize_scp_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ClassDB::register_class<PetzScpResource>();
	scp_loader.instantiate();
	ResourceLoader::add_resource_format_loader(scp_loader);
}

void uninitialize_scp_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	ResourceLoader::remove_resource_format_loader(scp_loader);
	scp_loader.unref();
}