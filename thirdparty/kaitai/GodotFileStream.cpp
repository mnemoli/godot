#include "GodotFileStream.h"

int GodotFileStream::underflow() {
	{
		if (_file->eof_reached()) {
			return EOF;
		} else {
			size_t pos = _file->get_position();
			uint8_t ret = _file->get_8();
			_file->seek(pos); // Required since get_8() advances the read head.
			return ret;
		}
	}
}

std::fpos<_Mbstatet> GodotFileStream::seekpos(std::fpos<_Mbstatet> posType, std::ios_base::openmode openmode) {
	_file->seek(posType);
	return _file->get_position();
}
