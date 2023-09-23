
#ifndef GODOT_PETZSCPRESOURCE_H
#define GODOT_PETZSCPRESOURCE_H

#include "core/io/resource.h"

class PetzScpResource: public Resource {
	GDCLASS(PetzScpResource, Resource);

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("get_start_state"), &PetzScpResource::get_start_state);
		ClassDB::bind_method(D_METHOD("get_action", "action_id"), &PetzScpResource::get_action);
		ClassDB::bind_method(D_METHOD("get_actions"), &PetzScpResource::get_actions);
        ClassDB::bind_method(D_METHOD("has_action", "action_id"), &PetzScpResource::has_action);
	}
private:
	int startState;
	Dictionary actions;

public:
	Error load_file(const String &path);
	int get_start_state();
	Dictionary get_action(int action_id);
    Dictionary get_actions();
    bool has_action(int action_id);
};

#endif //GODOT_PETZSCPRESOURCE_H
