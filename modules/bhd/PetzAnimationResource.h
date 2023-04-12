#ifndef GODOT_PETZANIMATIONRESOURCE_H
#define GODOT_PETZANIMATIONRESOURCE_H

#include "core/io/resource.h"

class PetzAnimationResource: public Resource {
	GDCLASS(PetzAnimationResource, Resource);

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("get_frame", "frame_id"), &PetzAnimationResource::get_frame);
		ClassDB::bind_method(D_METHOD("get_ball_sizes"), &PetzAnimationResource::get_ball_sizes);
	}
private:
	Array frames;
	Array ball_sizes;

public:
	Error load_file(const String &path);
	Dictionary get_frame(int frame_id);
	Array get_ball_sizes();
};

#endif //GODOT_PETZANIMATIONRESOURCE_H
