
#ifndef GODOT_GODOTFILESTREAM_H
#define GODOT_GODOTFILESTREAM_H

#include "core/io/file_access.h"

#include <istream>
#include <streambuf>

class GodotFileStream : public std::streambuf {

public:
	GodotFileStream(FileAccess *fa) {
		_file = fa;
	}
	int underflow() override;
	int uflow() override {
		return _file->eof_reached() ? EOF : _file->get_8();
	}

protected:
	pos_type seekpos(pos_type posType, std::ios_base::openmode openmode) override;

private:
	FileAccess *_file;
};

#endif //GODOT_GODOTFILESTREAM_H
