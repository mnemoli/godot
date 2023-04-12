
#include "PetzScpResource.h"
#include "core/io/file_access.h"
#include "scp.h"
#include "thirdparty/kaitai/GodotFileStream.h"
#include "thirdparty/kaitai/kaitaistream.h"
Error PetzScpResource::load_file(const String &path) {
	Error error;
	Ref<FileAccess> scp = FileAccess::open(path, FileAccess::READ, &error);
	if(error != OK) {
		if(scp.is_valid()) {
			scp->close();
			return error;
		}
	}
	GodotFileStream gstr(*scp);
	std::istream str(&gstr);
	kaitai::kstream ks(&str);
	scp_t data(&ks);
	startState = data.start_state();
	for(int i = 0; i < data.actions()->size(); i++) {
		auto kaction = data.actions()->at(i);
		Dictionary action;
		Array scripts;
		action["id"] = kaction->action_id();
		action["scriptCount"] = kaction->script_count();
		action["startState"] = kaction->start_state();
		action["endState"] = kaction->end_state();
		for(int j = 0; j < kaction->scripts()->size(); j++) {
			Array script;
			auto kscript = kaction->scripts()->at(j);
			for(int k = 0; k < kscript->command()->size(); k++) {
				script.push_back(kscript->command()->at(k));
			}
			scripts.push_back(script);
		}
		action["scripts"] = scripts;
		actions.push_back(action);
	}
	return OK;
}
int PetzScpResource::get_start_state() {
	return startState;
}
Dictionary PetzScpResource::get_action(int action_id) {
	return actions[action_id];
}
Array PetzScpResource::get_actions() {
	return actions;
}
