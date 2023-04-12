#ifndef BHD_H_
#define BHD_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "thirdparty/kaitai/kaitaistruct.h"
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class bhd_t : public kaitai::kstruct {

public:
	class animation_t;

	bhd_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, bhd_t* p__root = 0);

private:
	void _read();
	void _clean_up();

public:
	~bhd_t();

	class animation_t : public kaitai::kstruct {

	public:

		animation_t(uint16_t p_index, kaitai::kstream* p__io, bhd_t* p__parent = 0, bhd_t* p__root = 0);

	private:
		void _read();
		void _clean_up();

	public:
		~animation_t();

	private:
		std::vector<uint32_t>* m_frame_offsets;
		bool n_frame_offsets;

	public:
		bool _is_null_frame_offsets() { frame_offsets(); return n_frame_offsets; };

	private:
		std::vector<uint32_t>* m_frame_offsets2;
		bool n_frame_offsets2;

	public:
		bool _is_null_frame_offsets2() { frame_offsets2(); return n_frame_offsets2; };

	private:
		uint16_t m_index;
		bhd_t* m__root;
		bhd_t* m__parent;

	public:
		std::vector<uint32_t>* frame_offsets() const { return m_frame_offsets; }
		std::vector<uint32_t>* frame_offsets2() const { return m_frame_offsets2; }
		uint16_t index() const { return m_index; }
		bhd_t* _root() const { return m__root; }
		bhd_t* _parent() const { return m__parent; }
	};

private:
	bool f_frames;
	std::vector<animation_t*>* m_frames;

public:
	std::vector<animation_t*>* frames();

private:
	uint16_t m_frames_offset;
	uint16_t m_unknown1;
	uint16_t m_version;
	uint16_t m_num_balls;
	uint32_t m_start_frame_no;
	uint32_t m_total_frames;
	std::vector<uint16_t>* m_unknown2;
	std::vector<uint16_t>* m_ball_sizes;
	uint16_t m_animation_count;
	std::vector<uint16_t>* m_ends;
	bhd_t* m__root;
	kaitai::kstruct* m__parent;

public:
	uint16_t frames_offset() const { return m_frames_offset; }
	uint16_t unknown1() const { return m_unknown1; }
	uint16_t version() const { return m_version; }
	uint16_t num_balls() const { return m_num_balls; }
	uint32_t start_frame_no() const { return m_start_frame_no; }
	uint32_t total_frames() const { return m_total_frames; }
	std::vector<uint16_t>* unknown2() const { return m_unknown2; }
	std::vector<uint16_t>* ball_sizes() const { return m_ball_sizes; }
	uint16_t animation_count() const { return m_animation_count; }
	std::vector<uint16_t>* ends() const { return m_ends; }
	bhd_t* _root() const { return m__root; }
	kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // BHD_H_
