// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "bhd.h"

bhd_t::bhd_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, bhd_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = this;
	m_unknown2 = 0;
	m_ball_sizes = 0;
	m_ends = 0;
	m_frames = 0;
	f_frames = false;

	try {
		_read();
	} catch(...) {
		_clean_up();
		throw;
	}
}

void bhd_t::_read() {
	m_frames_offset = m__io->read_u2le();
	m_unknown1 = m__io->read_u2le();
	m_version = m__io->read_u2le();
	m_num_balls = m__io->read_u2le();
	m_start_frame_no = m__io->read_u4le();
	m_total_frames = m__io->read_u4le();
	m_unknown2 = new std::vector<uint16_t>();
	const int l_unknown2 = 11;
	for (int i = 0; i < l_unknown2; i++) {
		m_unknown2->push_back(m__io->read_u2le());
	}
	m_ball_sizes = new std::vector<uint16_t>();
	const int l_ball_sizes = num_balls();
	for (int i = 0; i < l_ball_sizes; i++) {
		m_ball_sizes->push_back(m__io->read_u2le());
	}
	m_animation_count = m__io->read_u2le();
	m_ends = new std::vector<uint16_t>();
	const int l_ends = animation_count();
	for (int i = 0; i < l_ends; i++) {
		m_ends->push_back(m__io->read_u2le());
	}
}

bhd_t::~bhd_t() {
	_clean_up();
}

void bhd_t::_clean_up() {
	if (m_unknown2) {
		delete m_unknown2; m_unknown2 = 0;
	}
	if (m_ball_sizes) {
		delete m_ball_sizes; m_ball_sizes = 0;
	}
	if (m_ends) {
		delete m_ends; m_ends = 0;
	}
	if (f_frames) {
		if (m_frames) {
			for (std::vector<animation_t*>::iterator it = m_frames->begin(); it != m_frames->end(); ++it) {
				delete *it;
			}
			delete m_frames; m_frames = 0;
		}
	}
}

bhd_t::animation_t::animation_t(uint16_t p_index, kaitai::kstream* p__io, bhd_t* p__parent, bhd_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_index = p_index;
	m_frame_offsets = 0;
	m_frame_offsets2 = 0;

	try {
		_read();
	} catch(...) {
		_clean_up();
		throw;
	}
}

void bhd_t::animation_t::_read() {
	n_frame_offsets = true;
	int v = index();
	if (index() > 0) {
		n_frame_offsets = false;
		m_frame_offsets = new std::vector<uint32_t>();
		const int l_frame_offsets = (_parent()->ends()->at(index()) - _parent()->ends()->at((index() - 1)));
		for (int i = 0; i < l_frame_offsets; i++) {
			m_frame_offsets->push_back(m__io->read_u4le());
		}
	}
	n_frame_offsets2 = true;
	if (index() == 0) {
		n_frame_offsets2 = false;
		m_frame_offsets2 = new std::vector<uint32_t>();
		const int l_frame_offsets2 = _parent()->ends()->at(index());
		for (int i = 0; i < l_frame_offsets2; i++) {
			m_frame_offsets2->push_back(m__io->read_u4le());
		}
	}
}

bhd_t::animation_t::~animation_t() {
	_clean_up();
}

void bhd_t::animation_t::_clean_up() {
	if (!n_frame_offsets) {
		if (m_frame_offsets) {
			delete m_frame_offsets; m_frame_offsets = 0;
		}
	}
	if (!n_frame_offsets2) {
		if (m_frame_offsets2) {
			delete m_frame_offsets2; m_frame_offsets2 = 0;
		}
	}
}

std::vector<bhd_t::animation_t*>* bhd_t::frames() {
	if (f_frames)
		return m_frames;
	std::streampos _pos = m__io->pos();
	m__io->seek(frames_offset());
	m_frames = new std::vector<animation_t*>();
	const int l_frames = animation_count();
	for (int i = 0; i < l_frames; i++) {
		m_frames->push_back(new animation_t(i, m__io, this, m__root));
	}
	m__io->seek(_pos);
	f_frames = true;
	return m_frames;
}
