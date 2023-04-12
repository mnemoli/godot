#include "PetzAnimationResource.h"
#include "bhd.h"
#include "core/io/file_access.h"
#include "thirdparty/kaitai/GodotFileStream.h"
#include "thirdparty/kaitai/kaitaistream.h"

Dictionary PetzAnimationResource::get_frame(int frame_id) {
	return frames.get(frame_id);
}

Error PetzAnimationResource::load_file(const String &path) {
	Error error;
	Ref<FileAccess> bhd = FileAccess::open(path, FileAccess::READ, &error);
	if(error != OK) {
		if(bhd.is_valid()) {
			bhd->close();
			return error;
		}
	}
	GodotFileStream gstr(*bhd);
	std::istream str(&gstr);
	kaitai::kstream ks(&str);
	bhd_t data(&ks);
	for(int i = 0; i < data.ball_sizes()->size(); i++) {
		ball_sizes.push_back(data.ball_sizes()->at(i));
	}
	for(int i = 0; i < data.frames()->size(); i++) {
		auto frame = data.frames()->at(i);
		auto offsets = i == 0 ? frame->frame_offsets2() : frame->frame_offsets();
		Ref<FileAccess> bdt = FileAccess::open(path.get_base_dir() + "/" + path.get_file().get_basename() + itos(i) + ".bdt", FileAccess::READ, &error);
		if(error != OK) {
			if(bhd.is_valid()) {
				bhd->close();
				return error;
			}
		}
		for(int j = 0; j < offsets->size(); j++) {
			Array ballarray;
			bdt->seek(offsets->at(j));
			auto headermin = Vector3(bdt->get_16(), bdt->get_16(), bdt->get_16());
			auto headermax = Vector3(bdt->get_16(), bdt->get_16(), bdt->get_16());
			auto tag = bdt->get_16();
			for(int ballindex = 0; ballindex < data.num_balls(); ballindex++) {
				Dictionary balldict;
				balldict["position"] = Vector3(static_cast<int16_t>(bdt->get_16()),static_cast<int16_t>(bdt->get_16()),static_cast<int16_t>(bdt->get_16()));
				balldict["rotation"] = Vector3(bdt->get_8(),bdt->get_8(),bdt->get_8());
				bdt->get_8();
				ballarray.push_back(balldict);
			}
			Dictionary frame_data;
			frame_data["ball_array"] = ballarray;
			frame_data["header_min"] = headermin;
			frame_data["header_max"] = headermax;
			frame_data["tag"] = tag;
			frames.push_back(frame_data);
		}
	}
	return OK;
}
Array PetzAnimationResource::get_ball_sizes() {
	return ball_sizes;
}
