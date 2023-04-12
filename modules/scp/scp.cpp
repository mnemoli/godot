// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "scp.h"

scp_t::scp_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, scp_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = this;
	m_actions = 0;
	m_scripts = 0;
	m__io__raw_scripts = 0;

	try {
		_read();
	} catch(...) {
		_clean_up();
		throw;
	}
}

void scp_t::_read() {
	m_intro = m__io->read_bytes(62);
	m_total_states = m__io->read_u4le();
	m_start_state = m__io->read_u4le();
	m_unknown = m__io->read_u8le();
	m_actioncount = m__io->read_u4le();
	m_actions = new std::vector<action_t*>();
	const int l_actions = actioncount();
	for (int i = 0; i < l_actions; i++) {
		m_actions->push_back(new action_t(m__io, this, m__root));
	}
	m_size_of_scripts = m__io->read_u4le();
	m__raw_scripts = m__io->read_bytes((size_of_scripts() * 4));
	m__io__raw_scripts = new kaitai::kstream(m__raw_scripts);
	m_scripts = new scripts_t(m__io__raw_scripts, this, m__root);
	m_ender = m__io->read_bytes(62);
}

scp_t::~scp_t() {
	_clean_up();
}

void scp_t::_clean_up() {
	if (m_actions) {
		for (std::vector<action_t*>::iterator it = m_actions->begin(); it != m_actions->end(); ++it) {
			delete *it;
		}
		delete m_actions; m_actions = 0;
	}
	if (m__io__raw_scripts) {
		delete m__io__raw_scripts; m__io__raw_scripts = 0;
	}
	if (m_scripts) {
		delete m_scripts; m_scripts = 0;
	}
}

scp_t::action_t::action_t(kaitai::kstream* p__io, scp_t* p__parent, scp_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_scripts = 0;
	f_scripts = false;

	try {
		_read();
	} catch(...) {
		_clean_up();
		throw;
	}
}

void scp_t::action_t::_read() {
	m_action_id = m__io->read_u4le();
	m_script_count = m__io->read_u4le();
	m_start_state = m__io->read_u4le();
	m_end_state = m__io->read_u4le();
	m_loop_modifier = m__io->read_u4le();
	m_unknown1 = m__io->read_u2le();
	m_unknown2 = m__io->read_u2le();
	m_unknown3 = m__io->read_u2le();
	m_unknown4 = m__io->read_u2le();
	m_start_offset = m__io->read_u4le();
}

scp_t::action_t::~action_t() {
	_clean_up();
}

void scp_t::action_t::_clean_up() {
	if (f_scripts) {
		if (m_scripts) {
			for (std::vector<script_t*>::iterator it = m_scripts->begin(); it != m_scripts->end(); ++it) {
				delete *it;
			}
			delete m_scripts; m_scripts = 0;
		}
	}
}

std::vector<scp_t::script_t*>* scp_t::action_t::scripts() {
	if (f_scripts)
		return m_scripts;
	kaitai::kstream *io = _root()->_io();
	std::streampos _pos = io->pos();
	io->seek(((86 + (_root()->actioncount() * 32)) + (start_offset() * 4)));
	m_scripts = new std::vector<script_t*>();
	const int l_scripts = script_count();
	for (int i = 0; i < l_scripts; i++) {
		m_scripts->push_back(new script_t(io, this, m__root));
	}
	io->seek(_pos);
	f_scripts = true;
	return m_scripts;
}

scp_t::scripts_t::scripts_t(kaitai::kstream* p__io, scp_t* p__parent, scp_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_scripts = 0;

	try {
		_read();
	} catch(...) {
		_clean_up();
		throw;
	}
}

void scp_t::scripts_t::_read() {
	m_scripts = new std::vector<script_t*>();
	{
		int i = 0;
		while (!m__io->is_eof()) {
			m_scripts->push_back(new script_t(m__io, this, m__root));
			i++;
		}
	}
}

scp_t::scripts_t::~scripts_t() {
	_clean_up();
}

void scp_t::scripts_t::_clean_up() {
	if (m_scripts) {
		for (std::vector<script_t*>::iterator it = m_scripts->begin(); it != m_scripts->end(); ++it) {
			delete *it;
		}
		delete m_scripts; m_scripts = 0;
	}
}

scp_t::script_t::script_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, scp_t* p__root) : kaitai::kstruct(p__io) {
	m__parent = p__parent;
	m__root = p__root;
	m_command = 0;

	try {
		_read();
	} catch(...) {
		_clean_up();
		throw;
	}
}

void scp_t::script_t::_read() {
	m_size = m__io->read_u4le();
	m_command = new std::vector<verbs_t>();
	const int l_command = (size() - 1);
	for (int i = 0; i < l_command; i++) {
		m_command->push_back(static_cast<scp_t::verbs_t>(m__io->read_u4le()));
	}
}

scp_t::script_t::~script_t() {
	_clean_up();
}

void scp_t::script_t::_clean_up() {
	if (m_command) {
		delete m_command; m_command = 0;
	}
}
